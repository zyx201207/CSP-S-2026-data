#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
#define pll pair<ll,ll>
#define pld pair<ld,ld>
typedef long long ll;
typedef long double ld;
typedef __int128 i128;
namespace io {
	using namespace std;
	inline ll read () {
		char x=getchar();
		ll ans=0,f=1;
		while (x<'0'||x>'9') {
			if (x=='-') {
				f=-1;
			}
			x=getchar();
		}
		while (x>='0'&&x<='9') {
			ans=(ans<<1)+(ans<<3);
			ans+=(x-'0');
			x=getchar();
		}
		return ans*f;
	}
	void print (ll x) {
		if (x<0) {
			putchar('-');
			x=-x;
		}
		if (x>=10) {
			print(x/10);
		}
		putchar(x%10+'0');
	}
}
using namespace io;
const ll N=5e5+5,mod=1e9+7,inf=2e18;
const ld eps=1e-6;
ll n,m,a[N],sum[N];
inline void solve () {
	n=read(),m=read();
	for (ll i=1;i<=n;i++) {
		a[i]=read();
	}
	sort(a+1,a+1+n);
	for (ll i=1;i<=n;i++) {
		sum[i]=sum[i-1]+a[i];
	}
	ll ans=0;
	for (ll i=1;i<=n;i++) {
		ll l=1,r=i,cnt=0;
		while (l<=r) {
			ll mid=(l+r)>>1;
			if (a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m) {
				cnt=i-mid+1;
				r=mid-1;
			}
			else {
				l=mid+1;
			}
		}
		ans=max(ans,cnt);
	}
	print(ans);
}
int main () {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll T=1;
	while (T--) {
		solve();
	}
	return 0;
}