#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m, sum[500005];
int a[500005];
bool check (int mid) {
	int ans = 0x3f3f3f3f3f3f3f3f;
	for (int i = 1; i <= n - mid + 1; i++) {
		int sum1 = 0;
		/*
		for (int j = i; j < i + mid - 1; j++) {
			sum1 += a[i + mid - 1] - a[j];
		}
		*/
		sum1 = (mid - 1) * a[i + mid - 1] - (sum[i + mid - 2] - sum[i - 1]);
		ans = min (ans, sum1);
	}
//	cout << ans << ' ';
	return ans <= m;
}
signed main() {
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	stable_sort (a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
	}
	int l = 1, r = n;
	while (l < r) {
		int mid = l + r + 1 >> 1;
		if (check (mid)) l = mid;
		else r = mid - 1;
//		cout << l << '\n';
	}
	cout << l;
	return 0;
}
/*
5 8
-3 -1 2 2 7
5 5
1 2 4 8 9
*/