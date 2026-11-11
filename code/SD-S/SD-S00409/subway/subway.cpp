//16:31  1~8  32pts  o(n^3)
#include <iostream>
using namespace std;
const int M=1500;
const int N=510;
int c,n,m,d,q;
int w[M];
int k[N];
int a[N][51000];
int t[N][51000];
int ans_1[450][450];
int ans_2[1100][1100];
int x,y;
void ans1(){//1~8  32pts
	for(int i=0;i<=349;++i){
		for(int j=0;j<=349;++j){
			ans_1[i][j]=1e9;
		}
	}
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	for(int i=1;i<=n;++i){
		cin>>k[i];
		for(int j=1;j<=k[i];++j){
			cin>>a[i][j]>>t[i][j];
			//ans_1[a[i][j-1]][a[i][j]]=t[i][j-1]+t[i][j];
		}
		for(int x=1;x<=k[i];++x){
			for(int y=1;y<x;++y){
				ans_1[a[i][x]][a[i][y]]=ans_1[a[i][y]][a[i][x]]=min(t[i][x]+t[i][y],ans_1[a[i][x]][a[i][y]]);
			}
		}
	}
	for(int i=1;i<=m;++i){
		for(int j=i+1;j<=m;++j){
			for(int k=1;k<=m;++k){
				if(i!=j){
					ans_1[i][j]=ans_1[j][i]=min(ans_1[i][j],ans_1[i][k]+ans_1[k][j]);
				}
			}
		}
	}
	for(int i=1;i<=q;++i){
		cin>>x>>y;
		cout<<w[x]+w[y]+ans_1[x][y]<<endl;
	}
}
void ans2(){
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	for(int i=1;i<=n;++i){
		cin>>k[i];
		for(int j=1;j<=k[i];++j){
			cin>>a[i][j]>>t[i][j];
		}
		for(int x=1;x<=k[i];++x){
			for(int y=1;y<x;++y){
				if(ans_2[a[i][x]][a[i][y]]>0)
					ans_2[a[i][x]][a[i][y]]=ans_2[a[i][y]][a[i][x]]=min(t[i][x]+t[i][y],ans_2[a[i][x]][a[i][y]]);
				else
					ans_2[a[i][x]][a[i][y]]=ans_2[a[i][y]][a[i][x]]=t[i][x]+t[i][y];
			}
		}
	}
	for(int i=1;i<=q;++i){
		cin>>x>>y;
		cout<<w[x]+w[y]+ans_2[x][y];
	}
}
void ans3(){
	while(1){
		
	} 
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	ans1();
	return 0;
}
