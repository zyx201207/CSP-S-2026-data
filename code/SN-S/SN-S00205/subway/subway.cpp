#include<bits/stdc++.h>
//the m+k(1<=k<=n)-th poll means the super-poll of the k-th road

using namespace std;
#define ll long long
ll n,m,k[1000005],d,q,c;
ll w[1000006];
vector<pair<ll,ll>> p[1000005];
ll f[1005][1005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++) cin>>w[i];
	for(ll i=1;i<=n;i++){
		cin>>k[i];
		for(ll j=1;j<=k[i];j++){
			ll x,w;cin>>x>>w;
			p[x].push_back({m+i,w});
		}
	}
	for(ll i=1;i<=1001;i++){
		for(ll j=1;j<=1001;j++){
			f[i][j]=1e18;
			if(i==j) f[i][j]=0;
		}
	} 
	for(ll i=1;i<=m;i++){
		for(auto j:p[i]){
			for(auto k:p[i]){
				ll u=j.first,v=k.first;
				if(u==v)  continue;
				else f[u-m][v-m]=min(f[u-m][v-m],j.second+k.second);
			}
		}
	}
	for(ll k=1;k<=n;k++){
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	for(ll i=1;i<=q;i++){
		ll u,v;cin>>u>>v;
		if(u==v){
			cout<<0<<'\n';
			continue;
		} 
		ll ans=1e18;
		for(auto x:p[u]){
			for(auto y:p[v]){
				ans=min(ans,x.second+y.second+f[x.first-m][y.first-m]);
			}
		}
		cout<<ans+w[u]+w[v]<<'\n';
	} 
	return 0;
}
