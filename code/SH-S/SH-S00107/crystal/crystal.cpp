#include <iostream>
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;
ll n,m,a[500005]={0},ans=-1;
bool cmp(ll xx, ll yy) {
	return xx<yy;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for (ll i=1;i<=n;i++) {
		ll x;
		scanf("%lld",&x);
		a[i] = x+a[i-1];
	}
	sort(a+1,a+n+1,cmp);
	ll l=1,r=1;
	for (;;)  {
		ll tg=a[r]-a[r-1];
		ll cnt=tg*(r-l+1)-a[r]+a[l-1];
		if (cnt<=m) {
			if (r-l+1>ans) {
				ans = r-l+1;
			}
			r++;
			if (r>n) {
				break;
			}
		} else {
			l++;
		}
	}
	cout << ans;
	return 0;
}
