#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m, a[500005], ans = 1, sum[500005];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	sum[1] = a[1];
	int x = 1;
	for (int i = 2; i <= n; i++) {
		sum[i] = a[i] + sum[i - 1];
		while (sum[i - 1] - sum[x - 1] + m < a[i] * (i - x)) x++;
		ans = max(ans, i - x + 1);
	}
	cout << ans << '\n';
	return 0;
}
/*
5 8
-3 -1 2 2 7
5 5
1 2 4 8 9
48 min

*/
