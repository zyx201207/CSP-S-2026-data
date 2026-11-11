#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=505,M=5e5+5;
int c,n,m,d,q,w[M];
ll dis[N][N];
struct edge{
	int v,w;
}; vector<edge> g[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		while(k--){
			int u,wt;
			cin>>u>>wt;
			g[u].push_back({i,wt});
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int u=1;u<=m;u++){
		for(edge e1:g[u]){
			int v1=e1.v,w1=e1.w;
			for(edge e2:g[u]){
				int v2=e2.v,w2=e2.w;
				dis[v1][v2]=min(dis[v1][v2],(ll)w1+w2); 
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int u,v;
		cin>>u>>v;
		ll ans=1e18;
		for(edge e1:g[u]){
			int i=e1.v,w1=e1.w;
			for(edge e2:g[v]){
				int j=e2.v,w2=e2.w;
				ans=min(ans,w[u]+w[v]+dis[i][j]+w1+w2);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
