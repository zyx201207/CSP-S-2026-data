#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int n, m, a[N], sum[N];
int ans;
bool check(int x) {
	for (int i = 1; i <= n - x + 1; i++)
		if (a[i + x - 1] * x - (sum[i + x - 1] - sum[i - 1]) <= m) return 1;
	return 0;
}
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	int l = 0, r = 4e18;
	while (l < r) {
		int mid = (l + r + 1) >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l;
	return 0;
}