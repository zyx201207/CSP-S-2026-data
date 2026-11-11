#include <bits/stdc++.h>
using namespace std;
long long a[500005];
long long sum[500005], cnt[500005];
int n;
long long m;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1, j = i + 1; i < n; i++, j++) {
		cnt[i] = a[j] - a[i];
		sum[i] = sum[i - 1] + i * cnt[i];
		//	cout  << sum[i] <<  '\n';
	}
//	sum[n] = sum[n - 1] + (n - 1) * cnt[n - 1];
//	cout << sum[3] - sum[1];
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			cout << vis[i][j] << " ";
//		}
//		cout << '\n';
//	}
	int l = 1, r = n, ans = 0, mid;
	while (l <= r) {
		mid = (l + r) / 2;
		//cout << l << " " << r << " "  << ans << " " << mid << '\n';
		if (sum[mid - 1] <= m) {
			ans = max(ans, mid);
		}
		if (sum[mid - 1] > m) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	cout << ans;
	return 0;
}
