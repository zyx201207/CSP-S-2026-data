#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
int n, m;
int a[N];

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	if (m == 1) {
		cout << a[n];
	} else if (m == n) {
		int ans = a[1];
		for (int i = 2; i <= n; i++)
			ans = ans & a[i];
		cout << ans << "\n";
	} else if (m == n - 1) {
		int ans = a[2];
		for (int i = 3; i <= n; i++)
			ans = ans & a[i];
		cout << ans;
	} else if (m == 2) {
		int ans = 0;
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				ans = max(ans, a[i] & a[j]);
		cout << ans;
	} else {
		cout << a[n - m + 1];
	}
	return 0;
}