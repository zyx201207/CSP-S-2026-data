#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+5;
int f, n, m, a[N], sum[N], ans;

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + (i - 1) * (a[i] - a[i - 1]);
	for (int i = 1; i <= n; i++) { //调成a[i]的值
		int l = 0, r = i - 1;
		while (l <= r) {
			int mid = l + r >> 1; //前mid个不要
			if (sum[i] - mid * (a[i] - a[mid]) - sum[mid] <= m)
				f = mid, r = mid - 1;
			else
				l = mid + 1;
		}
		ans = max(ans, i - f);
	}
	cout << ans;
	return 0;
}