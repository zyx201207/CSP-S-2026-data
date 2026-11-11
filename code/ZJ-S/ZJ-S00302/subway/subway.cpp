#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
const int N=1e6+10,M=1e3+10,MOD=1e9+7;
ll c,n,m,d,qq,w[N],dis[2*N];
bool vis[2*N];
struct edge{
	ll v,w;
};
vector<edge> G[2*N];
struct node{
	ll v,dis;
	bool operator<(const node&o) const{
		return dis>o.dis;
	}
};
priority_queue<node> q;
void djgsl(ll s){
	for(ll i=1;i<=2*m+n;i++) dis[i]=LLONG_MAX;
	for(ll i=1;i<=2*m+n;i++) vis[i]=false;
	dis[s]=0; q.push({s,0});
	while(q.size()){
		node cur=q.top(); q.pop();
		if(vis[cur.v]) continue;
		vis[cur.v]=true;
		for(ll i=0;i<G[cur.v].size();i++){
			ll to=G[cur.v][i].v;
			ll ww=G[cur.v][i].w;
			if(dis[to]>dis[cur.v]+ww){
				dis[to]=dis[cur.v]+ww;
				q.push({to,dis[to]});
			}
		}
	}
}
int main(){
	fastio;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>qq;
	for(ll i=1;i<=m;i++){
		cin>>w[i];
		G[i].push_back({i+m,w[i]});
		G[i+m].push_back({i,w[i]});
	}
	for(ll i=1;i<=n;i++){
		ll k;
		cin>>k;
		while(k--){
			ll a,t;
			cin>>a>>t;
			G[m+a].push_back({2*m+i,t});
			G[2*m+i].push_back({m+a,t});
		}
	}
	while(qq--){
		ll x,y;
		cin>>x>>y;
		djgsl(x);
		cout<<dis[y]<<'\n';
	}
	return 0;
}
