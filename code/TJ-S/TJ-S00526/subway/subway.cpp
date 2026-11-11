#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+1;
ll c,n,m,d,q,k,x,y,ans=0x3f3f3f3f3f3f,tim;
ll w[N],vis[N];
vector<pair<ll,ll> >tre[N];
void dfs(ll x,ll y){
	if(x==y){
		ans=min(ans,tim);
		return;
	}
	for(ll i=0;i<tre[x].size();i++){
		ll v=tre[x][i].first,t=tre[x][i].second;
		if(!vis[v]){
			tim+=t,vis[v]=1;
			dfs(v,y);
			tim-=t,vis[v]=0;
		}
	}
	return;
}
void spe1(){
	ll a,b,c,d;
	for(ll i=1;i<=m;i++)
		scanf("%lld",&w[i]);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&k);
		scanf("%lld%lld",&a,&b,&c,&d);
		tre[a].push_back({c,b+d});
	}
	for(ll i=1;i<=q;i++){
		scanf("%lld%lld",&x,&y);
		vis[x];
		dfs(x,y);
		ans+=(w[x]+w[y]);
		ans=0x3f3f3f3f3f;
		printf("%lld\n",ans);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	spe1();
	return 0;
}

