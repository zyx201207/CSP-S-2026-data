#include<bits/stdc++.h>
#define ll long long
const ll N=2e6+100;
using namespace std;
ll C,T,n,K,ans;
vector<ll>g[N];
ll vis[N],f[N];
queue<ll>q;
void bfs(ll s){
	q.push(s);
	f[s]=1;
	while(!q.empty()){
		ll x=q.front();q.pop();
		for(ll i=0;i<g[x].size();i++){
			ll v=g[x][i];
			if(vis[v]&&!f[v]){
				q.push(v);
				f[v]=1;
			}
		}
	}
}
ll dis[N];
void tong(){
	for(ll i=1;i<=n;i++){
		dis[i]=1e18;
		if(vis[i]){
			dis[i]=0;
			q.push(i);
		}
	}
	while(!q.empty()){
		ll x=q.front();q.pop();
		for(ll i=0;i<g[x].size();i++){
			ll v=g[x][i];
			if(dis[v]>dis[x]+1){
				dis[v]=dis[x]+1;
				q.push(v);
			}
		}
	}
	ll ma=0;
	for(ll i=1;i<=n;i++)ma=max(ma,dis[i]);
	ans=min(ans,ma);
}
void dfs(ll cnt,ll sum){
	if(sum==K){
		for(ll i=1;i<=n;i++)f[i]=0;
		ll s=0;
		for(ll i=1;i<=n;i++){
			if(vis[i]&&!f[i]){
				s++;
				if(s>2){
					break;
				}
				bfs(i);
			}
		}
		if(s>2)return;
		tong();
		return;
	}
	if(cnt>n)return;
	if(n-cnt+1<K-sum)return;
	vis[cnt]=1;
	dfs(cnt+1,sum+1);
	vis[cnt]=0;
	dfs(cnt+1,sum);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&C,&T);
	while(T--){
		scanf("%lld%lld",&n,&K);
		for(ll i=1;i<=n;i++)g[i].clear();
		for(ll i=1;i<n;i++){
			ll a,b;
			scanf("%lld%lld",&a,&b);
			g[a].push_back(b);
			g[b].push_back(a);
		}
		ans=1e18;
		dfs(1,0);
		printf("%lld\n",ans);
	}
	return 0;
} 
