#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int a[N], sum[N], n, m, ans;
bool check(int mid, int i) {
	return a[i] * (i - mid + 1) - sum[i] + sum[mid - 1] <= m;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
		int l = 1, r = i;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (check(mid, i)) {
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		ans = max(ans, i - l + 1);
	}	
	cout << ans; 
	return 0;
}
/*
5 5
1 2 4 8 9
*/
