#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c;
ll n,m,d,q;
vector<ll> g[500010];
ll w[500010],k;
ll ans;
ll spfa(){
	
} 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++) cin>>w[i];
	for(ll i=1;i<=n;i++){
		cin>>k;
		ll a0,t0;
		cin>>a0>>t0;
		for(ll i=2;i<=k;i++){
			ll a,t;
			cin>>a>>t;
			g[a0].push_back({a,t+w[a]+w[a0]+t0});
			a0=a,t0=t;
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<spfa()<<endl; 
	}
	return 0;
} 
