#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M=5e5+9,INF=1e18;
ll c,n,m,d,q;
ll w[M];
ll k,a,t;
ll x,y;
ll hd[2*M],nE;
struct Edge{
	ll to,nxt,w;
}e[4*M];
void add(ll u,ll v,ll w){
	e[++nE]=(Edge){v,hd[u],w};
	hd[u]=nE;
}
ll ans=0;
void dfs(ll u,ll fa,ll d,ll s){
	if(d>=ans){
		return;
	}
	if(u==s){
		ans=d;
		return;
	}
	for(ll i=hd[u];i;i=e[i].nxt){
		ll v=e[i].to;
		if(v==fa){
			continue;
		}
		dfs(v,u,d+e[i].w,s);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(ll i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	ll pre=0;
	for(ll i=1;i<=n;i++){
		scanf("%lld",&k);
		for(ll j=1;j<=k;j++){
			scanf("%lld%lld",&a,&t);
			add(m+pre+j,a,t);
			add(a,m+pre+j,t);
			if(j!=1){
				add(m+pre+j-1,m+pre+j,0);
				add(m+pre+j,m+pre+j-1,0);
			}
		}
		pre+=k;
	}
	for(ll i=1;i<=q;i++){
		scanf("%lld%lld",&x,&y);
		ans=INF;
		dfs(x,0,0,y);
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}
