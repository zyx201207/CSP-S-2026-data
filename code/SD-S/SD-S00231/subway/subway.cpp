#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
typedef pair<ll,ll> pll;
const int N=515;
const int M=10615;
const ll inf=1e18;
int c,n,m,dd,q,k[N];
int w[M];ll dis[N][M];
bitset<M> vis;
vector<pii>e[M];
vector<int>tot[N];
void djk(int s,int id){
	priority_queue<pll,vector<pll>,greater<> > q;
	for(int ee=1;ee<=m+n;ee++)dis[id][ee]=inf,vis[ee]=0;
	dis[id][s]=0;
	q.push({0,s});
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto to:e[u]){
			ll v=to.first,w=to.second;
			if(dis[id][u]+w<dis[id][v]){
				dis[id][v]=dis[id][u]+w;
				q.push({dis[id][v],v});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>dd>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1,a,t;j<=k[i];j++){
			cin>>a>>t;
			tot[a].pb(i);
			e[i+m].pb({a,t}),e[a].pb({i+m,t});
		}
	}
	for(int i=1;i<=n;i++)djk(m+i,i);
	for(int i=1,x,y;i<=q;i++){
		cin>>x>>y;
		ll ans=inf;
		for(auto xx:tot[x]){
			for(auto yy:tot[y]){
				if(xx==yy){
					ans=min(ans,(ll)dis[xx][x]+dis[yy][y]+w[x]+w[y]);
				}else{
					if(dis[xx][m+yy]!=inf)ans=min(ans,(ll)dis[xx][m+yy]+dis[xx][x]+dis[yy][y]+w[x]+w[y]);	
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
----------------
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
