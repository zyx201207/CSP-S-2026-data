#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const ll N=2e5+7;

ll n;
ll a[N];char c[N];

ll ans=0;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	ll l=1,r=n;
	while(l<r){
		ll tmp=0;
		while(tmp<a[l]&&l<r){
			if(a[r]+tmp>=a[l]){
				if(c[l]!=c[r])ans+=a[r]-(a[r]+tmp-a[l]);
				a[r]=a[r]+tmp-a[l];
				break;
			}
			else{
				if(c[l]!=c[r])ans+=a[r];
				tmp+=a[r];
				--r;
			}
		}
		++l;
	}
	cout<<ans;
	return 0;
}