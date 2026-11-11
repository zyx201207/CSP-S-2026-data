#include <bits/stdc++.h>
#define N 2000010
using namespace std;
typedef long long ll;

inline ll read() {
	ll x = 0, f = 1;
	char ch = getchar();
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') f = -1;
	else x = ch - '0';
	ch = getchar();
	while (isdigit(ch)) {
		x = (x << 1) + (x << 3) + ch - '0';
		ch = getchar();
	}
	return x * f;
}
ll _, n, D, a[N], nxt[N], dp[N], dpC[N];
int main() {
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w" ,stdout);
	_ = read(); _ = read();
	while (_--) {
		n = read(); D = read();
		for (int i = 1; i <= n; ++i) a[i] = read();
		ll now = n; nxt[n] = n;
		for (int i = n - 1; i >= 1; --i) {
			while (a[now] - a[i] > D) --now;
			nxt[i] = now;
		}
		ll ans = 0;
		for (int L = 1; L <= n; ++L)
			for (int R = L + 1; R <= n; ++R) {
				//cout << L << " " << R << " --------\n";
				dp[R] = 0; dpC[R] = 1;
				for (int i = R - 1; i >= L; --i) {
					ll oT = min((ll)R, nxt[i]);
					ll mx = n + 1, mxC = 0;
					for (int j = i + 1; j <= oT; ++j) {
						if (dp[j] < mx) mx = dp[j], mxC = dpC[j];
						else if (dp[j] == mx) mxC += dpC[j];
					}
					dp[i] = mx + 1; dpC[i] = mxC;
					//cout << i << " " << dp[i] << " " << dpC[i] << "\n";
				}
				if (dpC[L] == 2) ++ans;//, cout << L << " " << R << "\n";
			}
		cout << ans << '\n';
	}
	return 0;
}
