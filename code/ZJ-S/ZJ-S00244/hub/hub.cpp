#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
using namespace std;
const ll N=2e6+5,inf=1e18;
ll wk,T,n,k,fa[N],cnt;
bool vis[N];
ll find(ll x){return fa[x]==x?x:fa[x]=find(fa[x]);}
inline void merge(ll x,ll y){
	x=find(x);y=find(y);
	if(x==y) return ;
	cnt--;fa[x]=y; 
}
vector<ll> G[N];
inline ll bfs(int s){
	queue<pll> q;
	q.push({0,s});
	while(q.size()){
		pll u=q.front();
		q.pop();
		if(vis[u.second]){return u.first;}
		for(auto v:G[u.second]){
			q.push({u.first+1,v});
		}
	}
}
signed main(){
	ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>wk>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) G[i].clear();
		for(int i=1;i<n;i++){
			ll x,y;cin>>x>>y;
			G[x].push_back(y);
			G[y].push_back(x);
		}
		ll ans=inf;
		for(int s=0;s<(1<<n);s++){
			cnt=__builtin_popcount(s);
			if(cnt!=k) continue; 
			for(int i=1;i<=n;i++) fa[i]=i,vis[i]=0;
			for(int i=1;i<=n;i++){
				if(s&(1<<i-1)){
					vis[i]=1;
				}
			}
			for(int i=1;i<=n;i++){
				if(vis[i]){
					for(auto v:G[i]){
						if(vis[v]) merge(i,v);
					}
				}
			}
			if(cnt<=2){
				ll mx=0;
				for(int i=1;i<=n;i++){
					if(vis[i]) continue;
					mx=max(mx,bfs(i));
				}
				ans=min(ans,mx);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
