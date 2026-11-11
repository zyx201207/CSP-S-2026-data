#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int n, m;
int a[N];
int ans;
bool cmp(int x, int y) {
	return x > y;
}
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	int full = 1;
	int rest = m;
	for (int i = 1; i <= n; ++i) {
		while (full < n && a[full + 1] + rest >= a[i]) {
			full++;
			rest -= (a[i] - a[full]);
		}
		ans = max(ans, full - i + 1);
		rest += (full - i) * (a[i] - a[i + 1]);
//		cout << full << " " << full - i + 1 << "\n";
	}
	cout << ans;
	return 0;
}
