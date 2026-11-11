#include <bits/stdc++.h>
#define int long long
using namespace std;
const int Maxn = 2e5 + 5;
int n, m, a[Maxn], b[Maxn], ans, maxx, cnt;

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		maxx = max(maxx, a[i]);
		int lg = __lg(a[i] + 1);
		cnt += ((1 << lg) == a[i] + 1);
	}
	if (cnt == n) {
		sort(a + 1, a + n + 1, greater <int> ());
		cout << a[m] << '\n';
	} else if (m == 1) {
		cout << maxx << '\n';
	} else if (m == 2) {
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				ans = max(ans, a[i] & a[j]);
		cout << ans << '\n';
	} else if (m == n) {
		ans = a[1];
		for (int i = 2; i <= n; i++)
			ans = (ans & a[i]);
		cout << ans << '\n';
	} else if (m == n - 1) {
		for (int i = 1; i <= n; i++) {
			int tmp = a[1];
			if (i == 1)
				tmp = a[2];
			for (int j = 1; j <= n; j++)
				if (j != i)
					tmp = (tmp & a[j]);
			ans = max(ans, tmp);
		}
		cout << ans << '\n';
	} else if (n <= 20) {
		for (int i = 1; i <= n - m; i++)
			b[i] = 0;
		for (int i = n - m + 1; i <= n; i++)
			b[i] = 1;
		do {
			int tmp = 0, pos = 0;
			for (int i = 1; i <= n; i++)
				if (b[i] == 1) {
					tmp = a[i];
					pos = i;
					break;
				}
			for (int i = pos + 1; i <= n; i++)
				if (b[i] == 1)
					tmp = (tmp & a[i]);
			ans = max(ans, tmp);
		} while (next_permutation(b + 1, b + n + 1));
		cout << ans << '\n';
	}
	return 0;
}