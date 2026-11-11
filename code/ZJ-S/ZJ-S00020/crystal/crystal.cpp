#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[500005], pre[500005];
bool check(int x) {
	for (int i = 1; i <= n - x + 1; i++) {
		if (a[i + x - 1] * x - (pre[i + x - 1] - pre[i - 1]) <= m) return 1;
	}
	return 0;
}
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
	int L = 0, R = n;
	while (L + 1 < R) {
		int mid = (L + R) >> 1;
		if (check(mid)) L = mid;
		else R = mid;
	}
	cout << L;
}
