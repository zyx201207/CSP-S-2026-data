#include<bits/stdc++.h>
using namespace std;
int w[1005],k[1005];
int c,n,m,d,q;
vector<int>b[5005];
int a[1005][505];
int f[1005][1005];
bool vis[1005][1005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	for(int i=1;i<=n;++i){
		cin>>k[i];
		for(int j=1;j<=k[i];++j){
			int x;
			cin>>x;
			b[x].push_back(i);
			vis[x][i]=1;
			int y;
			cin>>y;
			a[x][i]=y;
		}
	}
	int h[25];
	memset(f,0x3f3f3f,sizeof f);
	for(int i=1;i<=m;++i){
		f[i][i]=0;
	}
	for(int i=1;i<=m;++i){
		for(int j=1;j<=m;++j){
			for(int k=1;k<=500;++k){
				if(vis[i][k]&&vis[j][k]){
					f[i][j]=min(f[i][j],a[i][k]+a[j][k]);
				}
			}
		}
	}
	for(int k=1;k<=m;++k){
	for(int i=1;i<=m;++i){
		for(int j=1;j<=m;++j){
			if(i==j)continue;
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<f[x][y]+w[x]+w[y]<<'\n';
	}
}