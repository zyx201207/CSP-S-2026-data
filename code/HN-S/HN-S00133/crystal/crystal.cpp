#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int n, m, a[N], sum[N], ans;
bool check (int x, int pos) {
	return a[pos] * (pos - x + 1) - (sum[pos] - sum[x - 1]) > m;
}
signed main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i];
	for (int i = 1; i <= n; i++) {
		int l = 1, r = n;
		while (l < r) {
			int mid = (l + r) >> 1;
			if (check(mid, i)) l = mid + 1;
			else r = mid;
		}
		ans = max(ans, i - r + 1);
	}
	cout << ans;
	return 0;
}
// 15minÐ´ÍêAwA 
