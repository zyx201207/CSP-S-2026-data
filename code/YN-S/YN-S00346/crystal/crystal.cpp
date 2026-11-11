#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n, m;
int a[N], sum[N], ans = 1, dp[N];

bool check(int len) {
	int flag = 0;
	for (int i = 1; i + len - 1 <= n; i++) {
		int j = i + len - 1;
		if (a[j] * (len - 1) - (sum[j - 1] - sum[i - 1]) <= m) {
			flag = 1;
			ans = len;
			break;
		}
	}
	if (flag == 0) {
		return 0;
	}
	return 1;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
	}
	int flag = 0;
	int L = 1, R = n;
	while (L <= R) {
		int mid = (L + R) >> 1;
		if (check(mid)) {
			ans = max(ans, mid);
			L = mid + 1;
		} else {
			R = mid - 1;
		}
	}
	cout << ans;
	return 0;
}