#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
int a[500010], sum[500010];
bool check(int x) {
	int cnt = LLONG_MAX;
	for (int i = 1; i + x - 1 <= n; i++) {
		int r = i + x - 1;
		cnt = min(cnt, a[r] * x - (sum[r] - sum[i - 1]));
	}
//	cout << cnt << endl;
	return cnt <= m;
}
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
//	for (int i = 1; i <= n; i++) cout << a[i] << ' ';
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
	}
	int l = 1, r = n;
	while (l < r) {
		int mid = l + r + 1 >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l << endl;
	return 0;
}
