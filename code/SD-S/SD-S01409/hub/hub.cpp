#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const ll N=2e6+10;
ll c,t,n,k,ans,dis[N];
bool vis[N],flag[N];
vector<ll>vt[N];
bool check(){
	queue<ll>q;
	for(ll i=1;i<=n;i++)flag[i]=vis[i];
	for(ll i=1;i<=n;i++){
		if(flag[i]){
			q.push(i);
			flag[i]=0;
			break;
		}
	}
	while(!q.empty()){
		ll g=q.front();q.pop();
		for(ll i=0;i<vt[g].size();i++){
			ll v=vt[g][i];
			if(flag[v]){
				q.push(v);
				flag[v]=0;
			}
		} 
	}
	for(ll i=1;i<=n;i++){
		if(flag[i]){
			q.push(i);
			flag[i]=0;
			break;
		}
	}
	while(!q.empty()){
		ll g=q.front();q.pop();
		for(ll i=0;i<vt[g].size();i++){
			ll v=vt[g][i];
			if(flag[v]){
				q.push(v);
				flag[v]=0;
			}
		} 
	}
	for(ll i=1;i<=n;i++){
		if(flag[i])return false;
	}	
	return true;
}
ll bfs(){
	queue<ll>q;
	for(ll i=1;i<=n;i++){
		if(vis[i])q.push(i),dis[i]=0;
		else dis[i]=2e15;
	}
	while(!q.empty()){
		ll g=q.front();q.pop();
		for(ll i=0;i<vt[g].size();i++){
			ll v=vt[g][i];
			if(dis[v]>dis[g]+1){
				dis[v]=dis[g]+1;
				q.push(v);
			}
		}
	}
	ll res=0;
	for(ll i=1;i<=n;i++){
		res=max(res,dis[i]);
	}
	return res;
}
void dfs1(ll x,ll cnt){
	if(x==n+1){
		if(cnt!=k||!check())return;
		ans=min(ans,bfs());
		return;
	}
	dfs1(x+1,cnt);
	vis[x]=true;
	dfs1(x+1,cnt+1);
	vis[x]=false;
}
void solve(){
	scanf("%lld%lld",&n,&k);
	for(ll i=1;i<=n;i++)vt[i].clear();
	for(ll i=1;i<n;i++){
		ll u,v;
		scanf("%lld%lld",&u,&v);
		vt[u].push_back(v);
		vt[v].push_back(u);
	}
	if(n==k){
		printf("0/n");
		return;
	}
	if(n<=10){
		ans=2e15;
		dfs1(1,0);
		printf("%lld\n",ans);
		return;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--)solve();
	return 0;
} 
