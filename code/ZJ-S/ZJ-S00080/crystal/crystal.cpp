#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const ll N=5e5+7;

ll n,m;
ll a[N];

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	
	ll l=1,r=0,ans=0;
	ll cost=0;
	
	while(r<=n){
		++r;
		cost+=(r-l)*(a[r]-a[r-1]);
		while(cost>m&&l<=r){
			cost-=(a[r]-a[l]);
			++l;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}