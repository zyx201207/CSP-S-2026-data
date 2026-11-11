#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll c,n,m,d,Q;
ll w[500001];
ll e[501][501];
struct edge{
	ll to,p;
};
vector<edge> ne[501];
ll dis[501];
ll vis[501];
vector<pair<ll,ll>> ac[500001];
inline void djkstra(ll s){
	memset(dis,0x3f,sizeof(dis));
	fill(vis,vis+501,0);
	dis[s]=0;
	vis[s]=1;
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
	q.push({0,s});
	while(!q.empty()){
		pair<ll,ll> hd=q.top();
		q.pop();
		ll u=hd.second;
		for(auto i:ne[u]){
			int v=i.to,_w=i.p;
			if(dis[v]>dis[u]+_w){
				dis[v]=dis[u]+_w;
				if(!vis[v])q.push({dis[v],v});
				else vis[v]=1;
			}
		}
	}
}
int main(){
	int ccnt=0;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(e,0x3f,sizeof(e));
	cin>>c>>n>>m>>d>>Q;
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	for(ll i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(ll j=1;j<=k;j++){
			ll a,b;
			cin>>a>>b;
			ac[a].push_back({i,b});
		}
	}
	for(ll i=1;i<=m;i++){
		ll siz=ac[i].size();
		for(ll j=0;j<siz;j++){
			for(ll k=j+1;k<siz;k++){
				ll u=ac[i][j].first;
				ll v=ac[i][k].first;
				ll w=ac[i][j].second+ac[i][k].second;
				e[u][v]=min(e[u][v],w);
				e[v][u]=min(e[v][u],w);
			}
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=i+1;j<=n;j++){
			if(e[i][j]!=inf){
				ccnt++;
				ne[i].push_back({j,e[i][j]});
				ne[j].push_back({i,e[i][j]});
			}
		}
	}
	while(Q--){
		ll s,t;
		cin>>s>>t;
		ll ans=inf;
		for(auto i:ac[s]){
			djkstra(i.first);
			for(auto j:ac[t]){
				ans=min(ans,dis[j.first]+i.second+j.second+w[s]+w[t]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
