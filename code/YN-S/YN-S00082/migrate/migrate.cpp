#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 5, INF = 1e16;
int c, T, n, m;
int num[N];
int dis[N];
int val[N];

int low_bit(int x) {
	return x & -x;
}

void add(int x, int k) {
	for (int i = x; i <= n; i += low_bit(i))
		val[i] += k;
}

int query(int x) {
	int tot = 0;
	for (int i = x; i >= 1; i -= low_bit(i))
		tot += val[i];
	return tot;
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> num[i];
	if (c <= 10) {
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[j] = INF;
				val[j] = 0;
			}
			add(i, 1);
			add(i + 1, -1);
			dis[i] = 0;
			int pos = i, cant = i;
			for (int j = i; j <= n; j++) {
				int cur = query(j);
				ans += (cur == 2);
				while (pos <= n && dis[pos] <= dis[j])
					pos++;
				while (cant <= n && num[cant] - num[j] <= m)
					cant++;
				if (pos <= cant) {
					for (int k = pos; k < cant; k++)
						dis[k] = dis[j] + 1;
					add(pos, cur);
					add(cant, -cur);
				}
			}
		}
		cout << ans << '\n';
	} else if (11 <= c && c <= 12) {
		if (n <= 1) {
			cout << 0 << '\n';
			return;
		}
		int dif = num[2] - num[1], len = m / dif * 2 + 1;
		if (len <= 3) {
			cout << 0 << '\n';
		} else {
			cout << max(n - len + 2, 0LL) << '\n';
		}
	} else {
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			if (num[i] - num[1] <= m && num[n] - num[i] <= m)
				cnt++;
		if (cnt == 1) {
			int L = 1, R = 1, pos = 1, ans = 0;
			for (int i = 1; i <= n; i++) {
				while (pos <= n && num[i] - num[pos] > m)
					pos++;
				if (pos < i - 1) {
					while (L <= n && num[pos + 1] - num[L] > m)
						L++;
					while (R <= n && num[pos + 2] - num[R] > m)
						R++;
					ans += R - L;
				}
			}
			cout << ans << '\n';
		} else if (cnt > 1) {
			int can = 1, pos = 1, ans = 0;
			if (cnt == 2)
				ans = (n - cnt) * (n - cnt - 1) / 2;
			for (int i = 1; i <= n; i++) {
				while (can <= n && num[i] - num[can] > m)
					can++;
				while (pos <= n && num[can] - num[pos] > m)
					pos++;
				ans += pos - 1;
			}
			cout << ans << '\n';
		} else {
			cout << 0 << '\n';
		}
	}
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> T;
	while (T--)
		solve();
	return 0;
}