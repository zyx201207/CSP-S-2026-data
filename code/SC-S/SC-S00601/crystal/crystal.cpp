#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n, m, ans, a[N], pre[N];
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)	cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; ++i)	pre[i] = pre[i - 1] + a[i];
	for (int i = 1, j = 1; i <= n; ++i) {
		while (j <= i && pre[i] - pre[j - 1] + m < a[i] * (i - j + 1))	++j;
		ans = max(ans, i - j + 1);
	}
	cout << ans << '\n';
	return 0;
}