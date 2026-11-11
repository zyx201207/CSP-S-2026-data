#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const ll M=5e5+5,inf=1e9+5;
ll c,n,m,d,q;
ll qian[M];
vector<ll,pair<ll,ll> > edge[M*2];
void spfa(ll s,ll t){
	ll ans=inf;
	ll pri[m*2+5];
	bool f[m*2+5];
	memset(pri,inf,sizeof(pri));
	memset(f,0,sizeof(f));
	queue<ll> q;
	q.push(s);
	f[s]=1;
	pri[s]=0;
	while(!q.empty()){
		ll u=q.front();q.pop();
		for(ll i=0;i<(ll)edge[u].size();i++){
			ll v=edge[u][i].first,w=edge[u][i].second;
			if(w+pri[u]<pri[v]){
				pri[v]=w+pri[u];
				if(v==t) ans=min(ans,v);
				if(f[v]==0){
					f[v]=1;
					q.push(v);
				}
			}
		}
	}printf("%d\n",ans+qian[s]+qian[t]);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();cout.tie();
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(ll i=1;i<=m;i++) scanf("%d",&qian[i]);
	ll l=m;
	for(ll i=1;i<=n;i++){
		ll k;scanf("%d",&k);
		for(ll j=1;j<=k;j++){
			ll a,t;
			scanf("%d %d",&a,&t);
			if(j>1){
				edge[l].insert({l-1,0});
				edge[l-1].insert({l,0});
			} 
			edge[a].insert({++l,t});
			edge[l].insert({a,t});
		}
	}
	while(q--){
		ll x,y;
		cin>>x>>y;
		spfa(x,y);
	}
	return 0;
}
