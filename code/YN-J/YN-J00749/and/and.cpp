#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m, cnt;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	cnt = a[n];
	for (int i = n - 1; i > n - m; i--) {
		cnt &= a[i];
	}
	cout << cnt;
	return 0;
}