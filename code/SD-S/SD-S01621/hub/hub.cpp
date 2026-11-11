#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=2e6+10;
ll c,t,n,k,dis[N];
bool gone[N];
vector<ll>g[N],d;
void dfs(ll x,ll fa){
	for(auto i:g[x]){
		if(i-fa){
			dis[i]=dis[x]+1;
			dfs(i,x);
		}
	}
	if(g[x].size()==1)
		d.push_back(dis[x]);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&k);
		for(ll i=1;i<n;i++){
			ll u,v;
			scanf("%lld%lld",&u,&v);
			g[u].push_back({v,1});
			g[v].push_back({u,1});
		}
		memset(dis,0,sizeof(dis));
		dfs(1,0);
		sort(d.begin(),d.end());
		printf("%lld\n",d[0]+d[1]);
	} 
	return 0;
}
