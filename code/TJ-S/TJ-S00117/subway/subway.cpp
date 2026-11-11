#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
const int N=505;
const int inf=0x3f3f3f3f3f;
int e[N][N];
int a[N][N],t[N][N];
int w[N];
int c,n,m,d,q;
bool floyed(){
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			e[i][j]=inf;
			if(i==j){
				e[i][j]=1;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
		for(int j=1;j<=k;j++){
			for(int l=1;l<k;l++){
				if(a[i][j]!=a[i][l]){
					e[a[i][j]][a[i][l]]=e[a[i][l]][a[i][j]]=t[i][j]+t[i][l];
					//cout<<"e["<<a[i][j]<<"]["<<a[i][l]<<"]="<<t[i][j]+t[i][l]<<endl;
				}
				
			}
		}
	}
	//cout<<e[1][2]<<" "<<e[2][3]<<endl;
	floyed();
	//cout<<e[1][2]<<" "<<e[2][3]<<endl;
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=w[x]+e[x][y]+w[y];
		cout<<ans<<endl;
	}
	return 0;
} 
