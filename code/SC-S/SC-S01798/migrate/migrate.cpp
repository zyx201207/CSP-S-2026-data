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
const ll N=2e6+5,mod=1e9+7,inf=2e18;
const ld eps=1e-6;
ll n,d,a[N],pl[N],vis[N],num[N];
inline void solve () {
	n=read(),d=read();
	for (ll i=1;i<=n;i++){
		a[i]=read();
	}
	ll lt=n;
	for (ll i=n;i;i--) {
		while (a[lt]-a[i]>d) {
			lt--;
		}
		pl[i]=lt;
		num[i]=inf;
	}
	ll ans=0;
	for (ll i=1;i<=n;i++) {
		vis[i]=1;
		num[i]=0;
		for (ll j=i;j<=n;j++) {
//			if (num==j) {
//				num=pl[j];
//				cout<<i<<' '<<j<<'\n';
//			}
//			sum+=vis[j];
//			if (sum==2) {
//				ans++;
//				cout<<"*"<<i<<' '<<j<<'\n';
//			}
//			vis[num]+=sum;
//			vis[pl[j]+1]-=sum;
			if (vis[j]==2) {
				ans++;
			}
			for (ll k=j+1;k<=n;k++) {
				if (a[k]-a[j]<=d) {
					if (num[k]>num[j]+1) {
						num[k]=num[j]+1;
						vis[k]=0;
					}
					if (num[k]==num[j]+1) {
						vis[k]+=vis[j];
					}
				}
			}
		}
		for (ll j=1;j<=n+1;j++) {
			vis[j]=0;
			num[j]=inf;
		}
	}
	print(ans);
	puts("");
}
int main () {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll Cl=read(),T=read();
	while (T--) {
		solve();
	}
	return 0;
}
/*
0 1
8 3
0 1 2 4 8 10 11 13
*/