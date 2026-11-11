#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+9;
ll n,k,d[N],h[N];
vector<ll> a[N];
void dfs(ll x,ll fa,ll deep){
	d[x]=deep;
	ll t=0;
	for(auto q:a[x]){
		if(q!=fa){
			t=1;
			dfs(q,x,deep+1);
			h[x]=h[q]+1;
		}
	}
	if(t==0) h[x]=0;
	else if(h[x])
}
bool check(ll x){
	dfs(1,-1,0)
	ll cnt=0;
	
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ll C,T;
	cin>>C>>T;
	while(T--){
		cin>>n>>k;
		for(ll i=1;i<n;i++){
			ll u,v;
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		ll l=1,r=n,ans=1e18;
		while(l<=r){
			ll mid=(l+r)/2;
			if(check(mid)){
				r=mid-1;
				ans=mid;
			}
			else l=mid+1;
		}
		cout<<ans<<'\n';
		for(ll i=1;i<=n;i++){
			a[i].clear();
			
		} 
	}
	return 0;
}
