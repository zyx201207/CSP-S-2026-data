#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::min;
using std::max;
using std::vector;

#define int long long
static constexpr int inf = (int)(1.05e18);

#define fst first
#define scd second
#define pr std::pair<int,int>
#define ep emplace
#define eb emplace_back

static constexpr int MAXN = (int)(5e5) + 10;

int n, m, ans = 1;
int il[MAXN], sum[MAXN];

signed main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> il[i];
	std::sort(il + 1, il + n + 1);
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + il[i];
	for (int i = 1; i <= n; i++) {
		int L = 1, R = i, cur = inf;
		while (L <= R) {
			int mid = (L + R >> 1);
			int res = (i - mid + 1) * il[i] - (sum[i] - sum[mid - 1]);
			if (res <= m)
				cur = mid, R = mid - 1;
			else
				L = mid + 1;
		}
		ans = max(ans, i - cur + 1);
	}
	cout << ans << '\n';

	return 0;
}

/*
5 8
-3 -1 2 2 7

*/