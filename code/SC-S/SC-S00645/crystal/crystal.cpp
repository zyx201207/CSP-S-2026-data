#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 25;

int n, m, a[N], sum[N], ans;

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];	
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
		int l = 1, r = i;
		while (l < r) {
			int mid = (l + r) >> 1;
			int st = a[i] * (i - mid) - sum[i - 1] + sum[mid - 1];
			if (st > m) {
				l = mid + 1;
			} else {
				r = mid;
				ans = max(ans, i - mid + 1);
			}
		}
	}
	cout << ans << '\n';
	return 0;
}

/*

5 5
  1 2 4 8  9
0 1 3 7 15 24
i = 3, mid = 1;
*/