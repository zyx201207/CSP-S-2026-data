#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[5000005];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	int ans = sum;
	sort(a + 1, a + n + 1);
	int flag;
	for (int i = n; i >= 1; i--) {
		ans -= a[i];
//		cout << i << " " << ans << '\n';
		if (a[i] * (i - 1) <= (ans + m)) {
			cout << i << '\n';
			return 0;
		}
	}



	return 0;
}