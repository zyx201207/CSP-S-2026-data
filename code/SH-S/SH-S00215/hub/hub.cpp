#include<iostream>
#include<vector>
#include<queue> 
#include<cstdio>
using ll=long long;
using G=std::vector<std::vector<ll>>;
ll n,k;
G g;
std::vector<ll>fa,dep,now;
std::vector<bool>selected;
void dfs(ll p,ll u){
	for(ll v:g[u]){
		if(v!=p){
			fa[v]=u;
			dep[v]=dep[u]+1;
			dfs(u,v);
		}
	}
}
bool check(){
	std::vector<bool>vis(n+1);
	ll cc=0; 
	for(ll i=1;i<=n;i++){
		if(selected[i]&&!vis[i]){
			ll st=i;
			std::queue<ll>q;
			q.push(st);
			while(!q.empty()){
				ll u=q.front();
				q.pop();
				for(ll v:g[u]){
					if(selected[v]&&!vis[v]){
						vis[v]=true;
						q.push(v);
					}
				}
			}
			++cc;
		}
	}
	return cc<=2;
}
ll lca(ll u,ll v){
	if(dep[u]<dep[v]){
		ll t=u;
		u=v;
		v=t;
	}
	while(dep[u]>dep[v]){
		u=fa[u];
	}
	if(u==v){
		return u;
	}
	while(fa[u]!=fa[v]){
		u=fa[u];
		v=fa[v];
	}
	return fa[u];
}
ll dis(ll u,ll v){
	ll l=lca(u,v);
	return dep[u]+dep[v]-2*dep[l];
}
ll ans;
void select(ll pos,ll num){
	if(num==k+1){
		if(!check()){
			return;
		}
		ll mx=0;
		for(ll u=1;u<=n;u++){
			if(selected[u]){
				continue;
			}
			ll mn=n;
			for(ll v=1;v<=n;v++){
				if(selected[v]){
					mn=std::min(mn,dis(u,v));
				}
			}
			mx=std::max(mx,mn);
		}
		ans=std::min(ans,mx);
		return;
	}
	for(ll nxt=pos;nxt<=n-k+num;++nxt){
		now.push_back(nxt);
		selected[nxt]=true;
		select(nxt+1,num+1);
		now.pop_back();
		selected[nxt]=false;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ll c,t;
	std::cin>>c>>t;
	while(t--){
		std::cin>>n>>k;
		selected.assign(n+1,false);
		g.assign(n+1,{});
		fa.assign(n+1,0);
		dep.assign(n+1,0);
		for(ll i=1;i<n;++i){
			ll u,v;
			std::cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		fa[1]=-1;
		dep[1]=1;
		dfs(-1,1);
		ans=1e18;
		select(1,1);
		std::cout<<ans<<std::endl;
	}
	return 0; 
} // 20-30pts
