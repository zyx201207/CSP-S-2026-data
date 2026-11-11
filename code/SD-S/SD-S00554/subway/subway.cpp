#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505;
const int M=1e6+505;
struct Edge{
	ll v,w;
};
ll c,n,m,d,q,sum,dis[M];
bool vis[M];
vector<Edge> e[M];
priority_queue<pair<ll,ll> > pq;
void dijkstra(ll s){
	while(pq.size()) pq.pop();
	for(ll i=1;i<=sum;i++) dis[i]=1e18,vis[i]=0;
	dis[s]=0;
	vis[s]=1;
	pq.push({0LL,s});
	while(pq.size()){
		auto qq=pq.top();
		pq.pop();
		ll u=qq.second;
		for(auto ed : e[u]){
			ll v=ed.v;
			ll w=ed.w;
		    if(vis[v]) continue;
		    vis[v]=1;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				pq.push({-dis[v],v});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		ll ww;
		cin>>ww;
		e[i].push_back({i+m,ww});
		e[i+m].push_back({i,ww});
    }
    for(ll i=1;i<=n;i++){
    	ll k;
    	cin>>k;
    	while(k--){
    		ll a,t;
    		cin>>a>>t;
    		e[a+m].push_back({2*m+i,t});
    		e[2*m+i].push_back({a+m,t});
		}
	}
	while(q--){
		ll x,y;
		cin>>x>>y;
		sum=2*m+n;
		dijkstra(x);
		cout<<dis[y]<<'\n';
	}
	return 0;
} 
