#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2000010;
int c, T, n, pre[N], suf[N];
ll d, x[N], p[N], s[N], dp[N], ans;
namespace waste {
	ll p[N], s[N], dp[N], ans;
	void main () {
		fill (p, p + n + 2, 0);
		fill (s, s + n + 2, 0);
		p[1] = 1;
		for (int i = 2; i <= n; i++) {
			p[i] = p[i - 1];
			if (pre[i] <= pre[i + 1] - 1) {
				p[i] += p[pre[i + 1] - 1] - p[pre[i] - 1] + 1;
			} else {
				p[i]++;
			}
		}
		for (int i = n; i >= 1; i--) {
			p[i] -= p[i - 1];
		}
		s[n] = 1;
		for (int i = n - 1; i >= 1; i--) {
			s[i] = s[i + 1];
			if (suf[i - 1] + 1 <= suf[i]) {
				s[i] += s[suf[i - 1] + 1] - s[suf[i] + 1] + 1;
			} else {
				s[i]++;
			}
		}
		for (int i = 1; i <= n; i++) {
			s[i] -= s[i + 1];
		}
		fill (dp + 1, dp + n + 1, 0);
		for (int i = 1; i <= n; i++) {
			if (pre[i] <= i - 2) {
				dp[pre[i]] += s[i];
			}
		}
		ans = 0;
		for (int i = 1; i <= n; i++) {
			if (suf[i] >= i + 2) {
				ans += p[i] * dp[suf[i] - 1];
			}
		}
		printf ("%lld\n", ans);
	}
}
namespace brute {
	int dis[N], sta[N];
	ll ans;
	void main () {
		ans = 0;
		fill (sta + 1, sta + n + 1, 0);
		for (int i = 1; i <= n; i++) {
			fill (dis + 1, dis + i, i + 1);
			fill (sta + 1, sta + i + 1, 1);
			dis[i] = 0;
			for (int j = i; j >= 1; j--) {
				dis[pre[j]] = min (dis[pre[j]], dis[j] + 1);
			}
			for (int j = 2; j <= n; j++) {
				dis[j] = min (dis[j - 1], dis[j]);
			}
			for (int j = i; j >= 1; j--) {
				if (dis[j] == i + 1) {
					break;
				}
				if (suf[j] >= i) {
					continue;
				}
				bool ok1 = (suf[j] >= j + 1 && dis[suf[j] - 1] + 1 == dis[j]);
				bool ok2 = (suf[j] >= j + 2 && dis[suf[j] - 2] + 1 == dis[j]);
				sta[j] = sta[suf[j]] + ok1 * sta[suf[j] - 1] + ok2;
				if (sta[j] > 3) {
					sta[j] = 3;
				}
				if (sta[j] == 2) {
					ans++;
				}
			}
		}
		printf ("%lld\n", ans);
	}
}
int main () {
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	scanf ("%d%d", &c, &T);
	while (T --> 0) {
		scanf ("%d%lld", &n, &d);
		for (int i = 1; i <= n; i++) {
			scanf ("%lld", &x[i]);
		}
		for (int i = 1; i <= n; i++) {
			pre[i] = lower_bound (x + 1, x + n + 1, x[i] - d) - x;
			suf[i] = upper_bound (x + 1, x + n + 1, x[i] + d) - x - 1;
		}
		pre[n + 1] = n, suf[0] = 1;
		if (c <= 10) {
			brute::main ();
		} else {
			waste::main ();
		}
	}
	return 0;
}