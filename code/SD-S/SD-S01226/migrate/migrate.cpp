#include <bits/stdc++.h>
using namespace std;

#define il inline
#define ri register int
#define ll long long
#define inf 0x3f3f3f3f
il ll read();
const int N = 5005;

int c, T;
int n;
ll d, z[N], dp[N], len[N], ans;

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	c = read(); T = read();
	while (T--) {
		n = read();
		d = read();
		ans = 0;
		for (ri i=1; i<=n; i++) {
			z[i] = read();
		}
		for (ri s=1; s<=n-2; s++) {
			for (ri i=s; i<=n; i++) {
				len[i] = 1e9;
				dp[i] = 0;
			}
			dp[s] = 1;
			len[s] = 1;
			int r = s;
			for (ri i=s; i<=n; i++) {
				while (z[r + 1] - z[i] <= d && r + 1 <= n) {
					r++;
				}
				if (dp[i] == 2) ans++;
				if (r == i) break;
				for (ri j=i+1; j<=r; j++) {
					if (len[i] + 1 < len[j]) {
						len[j] = len[i] + 1;
						dp[j] = dp[i];
					} else if (len[i] + 1 == len[j]) {
						dp[j] += dp[i];
					}
				}
			}
		}
		cout << ans << "\n";
	} 
	return 0;
}
il ll read()
{
	ll x = 0, f = 1;
	char c = getchar();
	while (c < '0' || '9' < c) {
		if (c == '-') {
			f = -1;
		}
		c = getchar();
	}
	while ('0' <= c && c <= '9') {
		x = x * 10 + c - 48;
		c = getchar();
	}
	return x * f;
}
