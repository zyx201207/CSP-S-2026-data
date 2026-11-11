#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=5e5+10,N=505;
const ll INF=1e18;
int c,n,m,D,q;
struct edge{
	int x,t;
};
vector<edge> G[M];
int w[M];
ll dis[N][N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>D>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=INF;
		}
	}
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,t;
			cin>>x>>t;
			G[x].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<G[i].size();j++){
			int k=G[i][j].x;
			ll t1=G[i][j].t;
			for(int v=0;v<G[i].size();v++){
				int d=G[i][v].x;
				ll t2=G[i][v].t;
				dis[k][d]=min(dis[k][d],t1+t2);
//				cout<<k<<' '<<d<<' '<<dis[k][d]<<'\n';
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		ll ans=w[u]+w[v];
		ll cnt=INF;
		for(int i=0;i<G[u].size();i++){
			int k=G[u][i].x;
			ll t1=G[u][i].t;
			for(int j=0;j<G[v].size();j++){
				int d=G[v][j].x;
				ll t2=G[v][j].t;
				cnt=min(cnt,dis[k][d]+t1+t2);
			}
		}
		ans+=cnt;
		cout<<ans<<'\n';
	}
	return 0;
}

