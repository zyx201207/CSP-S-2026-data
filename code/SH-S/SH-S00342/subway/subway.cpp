#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,ll>
#define pll pair<ll,int>
using namespace std;

int c,n,m,d,q;
const int N=1e6+10,M=5e5+10;
vector<pii> g[N];
ll w[M];
ll dist[N];
int cnt;
priority_queue<pll,vector<pll>,greater<pll> > pq;
bool vis[N];
void dijkstra(int st){
	for(int i=1;i<=cnt;i++){
		dist[i]=1e18;
		vis[i]=0;
	}
	dist[st]=0;
	pq.push({0,st});
	while(!pq.empty()){
		int u=pq.top().second;
		pq.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].first;
			ll w=g[u][i].second;
			if(dist[v]>dist[u]+w){
				dist[v]=dist[u]+w;
				pq.push({dist[v],v});
			}
		}
	}
}
int S[510],E[510];
ll Dn[510][510];
vector<pii> dd[N];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//	freopen("subway4.in","r",stdin);
//	freopen("kskbl.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	cnt=m;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int lst;
		for(int j=1;j<=k;j++){
			int x;
			ll y;
			cin>>x>>y;
			dd[x].push_back({i,y});
			++cnt;
			if(j>1){
				g[lst].push_back({cnt,0});
				g[cnt].push_back({lst,0});
			}
			g[x].push_back({cnt,y});
			g[cnt].push_back({x,y});
			lst=cnt;
			if(j==1) S[i]=cnt;
			if(j==k) E[i]=cnt; 
		}
	}
	for(int i=1;i<=n;i++){
		dijkstra(S[i]);
		for(int j=1;j<=n;j++){
			Dn[i][j]=dist[E[j]];
		}
	}
	if(q<=200){
		while(q--){
			int st,ed;
			cin>>st>>ed;
			dijkstra(st);
			ll ans=w[st]+w[ed]+dist[ed];
			cout<<ans<<'\n';
		}
	}
	else{
		while(q--){
			int st,ed;
			cin>>st>>ed;
			ll ans=1e18;
			for(int i=0;i<dd[st].size();i++){
				int ss=dd[st][i].first;
				ll now=1e18;
				for(int j=0;j<dd[ed].size();j++){
					int ee=dd[ed][j].first;
					now=min(now,dd[st][i].second+dd[ed][j].second+Dn[ss][ee]);
				}
				ans=min(ans,now);
			}
			ans+=w[st]+w[ed];
			cout<<ans<<'\n';
		}
	}
	return 0;
}
