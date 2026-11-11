#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,cc,t,c[1000010],dis[1000010],ans;
bool vis[1000010];
vector<ll> e[1000010];
inline void solve(ll x){
	vis[x]=true;
	ll sz=e[x].size();
	for(int i=0;i<sz;i++){
		ll y=e[x][i];
		if(!vis[y]&&c[y]==1){
			solve(y);
		}
	}
}
inline void dfs(ll nw,ll gs){
	if(nw==n+1){
		if(gs!=k) return;
		for(int i=1;i<=n;i++) vis[i]=false;
		ll cnt=0;
		for(int i=1;i<=n;i++){
			if(!vis[i]&&c[i]==1){
				cnt++;
				solve(i);
			}
		}
		if(cnt<=2){
			for(int i=1;i<=n;i++) dis[i]=1e18;
			queue<ll> q;
			for(int i=1;i<=n;i++){
				if(c[i]==1){
					dis[i]=0;
					q.push(i);
				}
			}
			while(!q.empty()){
				ll x=q.front();
				q.pop();
				ll sz=e[x].size();
				for(int i=0;i<sz;i++){
					ll y=e[x][i];
					if(dis[y]>dis[x]+1){
						dis[y]=dis[x]+1;
						q.push(y);
					}
				}
			}
			ll res=0;
			for(int i=1;i<=n;i++){
				res=max(res,dis[i]);
			}
			ans=min(ans,res);
		}
		return;
	}
	c[nw]=1;
	dfs(nw+1,gs+1);
	c[nw]=0;
	dfs(nw+1,gs);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&cc,&t);
	while(t--){
		ans=1e18;
		scanf("%lld%lld",&n,&k);
		for(int i=1;i<=n;i++) e[i].clear();
		for(int i=1;i<n;i++){
			ll u,v;
			scanf("%lld%lld",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs(1,0);
		printf("%lld\n",ans);
	}
	return 0;
}
