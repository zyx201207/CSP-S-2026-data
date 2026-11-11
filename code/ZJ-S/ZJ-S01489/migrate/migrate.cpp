#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 10;
typedef long long ll;
typedef pair<int, int> pii;

int c, t, n;
ll d, a[N], ans;

void solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	ans = 0;
	for (int l = 1; l <= n; l ++)
		for (int r = l + 1; r <= n; r ++) {
			int cnt = 0;
			for (int i = l + 1; i + 2 <= r; i ++) {
				if (a[i + 1] - a[l] <= d && a[i + 2] - a[l] > d && a[r] - a[i] <= d && a[r] - a[i - 1] > d)
					cnt ++;
				if (cnt > 1) break;
			}
			if (cnt == 1) ans ++;
		}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin), freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t --) solve();
	return 0;
}