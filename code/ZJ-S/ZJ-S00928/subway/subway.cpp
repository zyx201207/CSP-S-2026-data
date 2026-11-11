#include<bits/stdc++.h>
using namespace std;
struct Edge{
	int to,dist;
	Edge(int t,int d):to(t),dist(d){}
};
int c,n,m,d,q;
int W[500000+5],v[500000+5],t[20005];
int g[10005][10005],f[10005][10005],vis[10005][10005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			g[i][j]=1e9;
			f[i][j]=1e9;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>W[i];
	}
	for(int i=1;i<=n;i++){
		int num;
		cin>>num;
		for(int j=1;j<=num;j++){
			cin>>v[j]>>t[j];
		}
		for(int k=1;k<=num;k++){
			for(int j=1;j<=num;j++){
				if(k!=j){
					g[v[k]][v[j]]=min(t[k]+t[j],g[v[k]][v[j]]);
					g[v[j]][v[k]]=min(t[k]+t[j],g[v[j]][v[k]]);
					vis[v[k]][v[j]]=1;
					vis[v[j]][v[k]]=1;
				}
			}
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(vis[i][j]==1) continue;
				g[i][j]=min(g[i][k]+g[k][j],g[i][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<W[x]+W[y]+g[x][y]<<endl;
	}
	return 0;
}
