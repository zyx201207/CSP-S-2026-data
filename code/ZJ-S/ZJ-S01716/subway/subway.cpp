#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long w[1000000];
int ki;
int k[505][100000];
int f[100000][505]={0}; 
long long t[505][100000];
long long ans=0;
long long Min=1e9;
int vis[100000]={0};
int x1,y2;
void bfs(int x,int y,int sum){
	vis[y]=1;
	if(y==x){
		if(Min>=sum){
			Min=sum;
		} 
		return ;
	}
	for(int i=1;i<=n;i++){
//		cout<<i<<endl;
		if(f[y][i]==1){
//			cout<<0<<endl;
			for(int j=1;j<=m;j++){
//				cout<<i<<" "<<j<<" "<<y<<endl;
//				if(f[j][i]==1)cout<<1<<endl;
//				if(vis[j]==0)cout<<2<<endl;
				if(f[j][i]==1 && vis[j]==0){
//					cout<<3<<endl;
					bfs(x,j,sum+t[i][y]+t[i][j]);
				}
			}
		}
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i]; 
	}
	for(int i=1;i<=n;i++){
		cin>>ki;
		int num=1;
		for(int j=1;j<=ki;j++){
			cin>>k[i][j];
			cin>>t[i][k[i][j]];
			f[k[i][j]][i]=1;
		}
	}
	for(int i=1;i<=q;i++){
		for(int z=0;z<=m;z++){
			vis[z]=0;
		}
		ans=0;
		cin>>x1>>y2; 
		ans+=w[x1];
		ans+=w[y2];
		bfs(x1,y2,ans);
		cout<<Min<<endl;
		Min=1e9;
	}
	return 0;
}
