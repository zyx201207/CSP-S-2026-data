#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::min;
using std::max;
using std::vector;

#define int long long
static constexpr int inf = (int)(1e16);

#define fst first
#define scd second
#define pr std::pair<int,int>
#define ep emplace
#define eb emplace_back

int testid;

namespace Solve1 {

	static constexpr int MAXN = 5010;

	int n, d, x[MAXN];
	int dp[MAXN][MAXN], cnt[MAXN][MAXN];
	int sum[MAXN][MAXN];
	int nxt[MAXN];

	void solve() {
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			cin >> x[i];
		if (n == 1)
			return cout << 0 << '\n', void();
		for (int i = 1; i <= n; i++)
			std::fill(dp[i], dp[i] + n + 1, inf);
		for (int i = 1; i <= n; i++)
			std::fill(cnt[i], cnt[i] + n + 1, 0);
		for (int i = 1; i <= n; i++)
			dp[i][i] = 1, cnt[i][i] = 1, sum[i][i] = 1;

		for (int i = 1; i < n; i++)
			for (int j = i + 1; j <= n; j++)
				if (x[j] - x[i] <= d)
					dp[i][j] = 1, cnt[j][i] = 1;
		for (int i = 1; i <= n; i++)
			for (int j = i; j >= 1; j--)
				sum[i][j] = sum[i][j + 1] + cnt[i][j];
		for (int i = 1; i <= n; i++)
			nxt[i] = std::upper_bound(x + 1, x + n + 1, x[i] + d) - x - 1;
		for (int k = 3; k <= n; k++) {
			for (int l = 1; l + k - 1 <= n; l++) {
				int r = l + k - 1, res = -1;
				if (x[r] - x[l] <= d)
					continue;
				int pos = nxt[l];
				if (pos == l) {
					cnt[l][r] = 0;
					continue;
				}
				int L = l + 1, R = pos;
				dp[l][r] = dp[pos][r] + 1;
				while (L <= R) {
					int mid = (L + R >> 1);
					if (dp[mid][r] + 1 == dp[l][r])
						res = mid, R = mid - 1;
					else
						L = mid + 1;
				}
				cnt[l][r] = sum[r][res] - sum[r][pos + 1];
				sum[r][l] = sum[r][l + 1] + cnt[l][r];
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
			for (int j = i + 2; j <= n; j++)
				if (cnt[i][j] == 2)
					ans++;
		cout << ans << '\n';
	}

	void Solve() {
		int n0;
		cin >> n0;
		while (n0--)
			solve();
	}

}

namespace Solve2 {
	static constexpr int MAXN = (int)(2e6) + 10;
	int n, d, x[MAXN];
	void solve() {
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			cin >> x[i];
		if (n == 1)
			return cout << 0 << '\n', void();
		int dif = x[2] - x[1];
		int q = d / dif, tot = 2 * q - 1;
		if (q <= 1)
			cout << 0 << '\n';
		else
			cout << max(0ll, n - tot) << '\n';
	}
	void Solve() {
		int n0;
		cin >> n0;
		while (n0--)
			solve();
	}
}

signed main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	cin >> testid;

	if (testid == 11 || testid == 12)
		Solve2::Solve();
	else
		Solve1::Solve();

	return 0;
}

/*
0 1
4 2
1 2 3 4

*/