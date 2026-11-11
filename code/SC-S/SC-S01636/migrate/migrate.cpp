#include <stdio.h>
//#include <iostream>
#define get getchar_unlocked
#define put putchar_unlocked
#define min(x,y) ((x) < (y) ? (x) : (y))
using namespace std;
using ll = long long;
ll read() {
	char c = get();
	ll res = 0, sg = 1;
	while ('0' > c || '9' < c) {
		if (c == '-') sg = -1;
		c = get();
	}
	while ('0' <= c && c <= '9') {
		res = res * 10 + (c - '0');
		c = get();
	}
//	int res;
//	cin >> res;
	return res * sg;
}
using namespace std;
//using ll = long long;
void out(ll x) {
	printf("%lld\n", x);
}
ll c,t,n,d,a[2000005],minn[2000005],dp[2000005];
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c = read();
	t = read();
	if (c <= 10) {
		while (t--){
			n = read();
			d = read();
			ll ans = 0;
			for (int i = 1;i <= n;++i) a[i] = read();
			for (int l = 1;l <= n;++l){
				dp[l] = 1;
				minn[l] = 0;
				for (int r = l + 1,i = l;r <= n;++r){
					while (a[r] - a[i] > d) ++i;
					if (i + 1 < r && minn[i] == minn[i + 1] && (i + 2 >= r || minn[i + 1] != minn[i + 2]))
						dp[r] = dp[i] + dp[i + 1];
					else if (i + 1 < r && minn[i] == minn[i + 1] && (i + 2 < r && minn[i + 1] == minn[i + 2]))
						dp[r] = 5;
					else if (i < r) dp[r] = dp[i];
					else dp[r] = 0;
					if (i < r) minn[r] = minn[i] + 1;
					else minn[r] = 1e18;
					if (dp[r] == 2) ++ans;//,cerr << l << " -> " << r << endl;
				}
				
			}
			out(ans);
		}
	} else if (c == 11 || c == 12){
		while (t--){
			n = read();
			d = read();
			for (int i = 1;i <= n;++i) a[i] = read();
			if (n == 1) out(1ll);
			else {
//				cerr << c << endl;
				ll k = d / (a[2] - a[1]),ans = 0;
				if (k < 2) {
					out(0ll);
					continue;
				}
				for (int i = 1;i <= n;++i)
					if (i - 2 * k + 1 > 0) ++ans;
				out(ans);
			}
		}
	} else {
		while (t--) out(0ll);
	}
	return 0;
}