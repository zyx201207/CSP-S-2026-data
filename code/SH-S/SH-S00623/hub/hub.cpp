#include<bits/stdc++.h>
#define pll pair<ll,ll>
#define mkp make_pair
#define fi first
#define se second
using namespace std;
typedef long long ll;
const ll N=1e6+9;
const ll INF=1e18;
/*
select the top of the two connected block
then get down
*/
ll cid,Tcase;
ll n,k;
ll hd[N],to[2*N],nxt[2*N],cntE;
void addedge(ll u,ll v){
	to[++cntE]=v;
	nxt[cntE]=hd[u];
	hd[u]=cntE;
}
ll p[N],dep[N],mxd[N];
ll sz[N],dfn[N],ma[N],timer;
void dfs(ll u,ll pa){
	p[u]=pa;
	dep[u]=dep[pa]+1;
	mxd[u]=0;
	ma[dfn[u]=++timer]=u;
	sz[u]=1;
	for(ll i=hd[u];i;i=nxt[i]){
		ll v=to[i];
		if(v==pa) continue;
		dfs(v,u);
		sz[u]+=sz[v];
		mxd[u]=max(mxd[u],mxd[v]+1);
	}
//	cout<<u<<" "<<mxd[u]<<'\n';
}
ll cost[N];
void solvebf(){ 
	ll ans=n;
	for(ll rt1=1;rt1<=n;rt1++){
//		cout<<"from "<<rt1<<'\n';
		timer=0;
		dfs(rt1,0);
		for(ll rt2=1;rt2<=n;rt2++)if(rt2!=rt1){
			ll u=rt2;
			ll cur=0;
			while(p[u]!=rt1){
				ll tmp=0;
				for(ll i=hd[p[u]];i;i=nxt[i]){
					ll v=to[i];
					if(v==p[p[u]]||v==u) continue;
					tmp=max(tmp,mxd[v]+1);
				}
				u=p[u];
				cur=max(cur,min(dep[u]-dep[rt1],dep[rt2]-dep[u])+tmp);
			}
			for(ll i=1;i<=n;i++) cost[i]=0;
			for(ll _=dfn[rt2]+1;_<dfn[rt2]+sz[rt2];_++) cost[mxd[ma[_]]]++;
			for(ll _=dfn[rt1]+1;_<dfn[rt1]+sz[rt1];_++) cost[mxd[ma[_]]]++;
			for(ll _=dfn[u];_<dfn[u]+sz[u];_++) cost[mxd[ma[_]]]--;
			ll res=n;
			for(ll i=n;i>=cur;i--){
				cost[i]+=cost[i+1];
				if(cost[i]+2<=k) res=i;
			}
//			cout<<res<<'\n';
			ans=min(ans,res);
		}
	}
	cout<<ans<<'\n';
}
void solve(){
	
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>cid>>Tcase;
	while(Tcase--){
		cin>>n>>k;
		for(ll i=1;i<=n-1;i++){
			ll u,v;
			cin>>u>>v;
			addedge(u,v);
			addedge(v,u);
		}
		if(n<=1000) solvebf();
		else solve();
		cntE=0;
		for(ll i=1;i<=n;i++) hd[i]=0;
	}
	return 0;
}
