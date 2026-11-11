#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
const int N = 3e5 + 5;
int a[N];
int ans = -1;

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cout.tie(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int flag = 0;
	sort(a + 1, a + n + 1);
	for (int i = n; i >= 1; i--) {
		if (a[i] != a[i - 1]) {
			flag++;
		}
		if (flag == m) {
			cout << a[i];
			return 0;
		}
	}
//	int x = 0;
//	for (int i = 1; i <= n; i++) {
//		x = a[i];
//		for (int y = i; y <= n; y++) {
//			for (int j = y; j <= m; j++) {
//				x = x & a[y];
//				cout << x << " ";
//			}
//		}
//		ans = max(ans, x);
//		x = 0;
//	}
//	cout << '\n' << ans;
	return 0;
}
