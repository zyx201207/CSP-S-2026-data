#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1005;
ll c,t,n,k,fa[N],dep[N],siz[N],son[N],top[N],vis[N];
vector<ll> g[N];
void dfs1(ll u,ll f){
	fa[u]=f;
	dep[u]=dep[f]+1;
	siz[u]=1;
	for(ll v : g[u]){
		if(v==f) continue;
		dfs1(v,u);
		siz[u]+=siz[v];
		if(siz[v]>siz[son[u]]) son[u]=v;
	}
}
void dfs2(ll u,ll f){
	if(son[u]){
		top[son[u]]=top[u];
		dfs2(son[u],u);
	}
	for(ll v : g[u]){
		if(v==f||v==son[u]) continue;
		top[v]=v;
		dfs2(v,u);
	}
}
ll lca(ll x,ll y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		x=fa[top[x]];
	}
	return (dep[x]<dep[y]?x:y);
}
void dfs(ll u){
	vis[u]=2;
	for(ll v : g[u]){
		if(vis[v]==1){
			dfs(v);
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(ll i=1;i<=n;i++){
			g[i].clear();
			son[i]=0;
		}
		for(ll i=1;i<n;i++){
			ll u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dep[1]=0;
		top[1]=1;
		dfs1(1,1);
		dfs2(1,1);
		ll ans1=LLONG_MAX;
		for(ll i=1;i<(1<<n);i++){
			vector<ll> s;
			for(ll j=0;j<n;j++){
			    vis[j+1]=0;
				if((i>>j)&1){
					s.push_back(j+1);
					vis[j+1]=1;
				}
			}
			if(s.size()!=k) continue;
			ll cnt=0;
			for(ll v : s){
				if(vis[v]==1){
					dfs(v);
					cnt++;
				}
			}
			if(cnt>2) continue;
			ll ans0=0;
			for(ll j=1;j<=n;j++){
				ll ans=LLONG_MAX;
				for(ll v : s){
					ans=min(ans,dep[j]+dep[v]-dep[lca(j,v)]*2);
				}
				ans0=max(ans0,ans);
			}
			ans1=min(ans1,ans0);
		}
		cout<<ans1<<endl;
	}
	return 0;
}
