#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
int dp[N];
int a[N];
int p[N];
mt19937 rng(time(0));
auto st = clock();

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= m; i++) {
		p[i] = 1;
	}
	if (n * m <= 4e8) {
		dp[0] = 2147483647;
		for (int i = 1; i <= n; i++) {
			for (int j = m; j >= 1; j--) {
				dp[j] = max(dp[j], dp[j - 1] & a[i]);
			}
		}
		cout << dp[m] << "\n";
	} else {
		int cnt = 0;
		int maxn = 0;
		while (cnt <= 5e8 / n) {
			cnt++;
			shuffle(p + 1, p + 1 + n, rng);
			int ans = (1 << 30) - 1;
			for (int i = 1; i <= n; i++) {
				if (p[i])
					ans &= a[i];
			}
			maxn = max(maxn, ans);
		}
		cout << maxn << "\n";
	}
	return 0;
}
/*
4 2
3 15 12 12
*/