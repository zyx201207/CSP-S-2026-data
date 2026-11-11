#include <bits/stdc++.h>
#define int long long
#define pil pair <int, int>
using namespace std;
const int N = 5e5 + 10;
int a[N], sum[N];
int n, m;
bool cmp(int x, int y) {
	return x > y;
}
int bs(int p) {
	int l = p, r = n;
	while (l < r) {
		int mid = (l + r) / 2;
		if (a[p] * (mid - p + 1) - (sum[mid] - sum[p - 1]) > m) {
			r = mid;
		}
		else {
			l = mid + 1;
		}
	}
	if (a[p] * (l - p + 1) - (sum[l] - sum[p - 1]) <= m) {
		return l - p + 1;
	}
	else {
		return l - p;
	}
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i ++) {
		sum[i] = sum[i - 1] + a[i];	
	}
//	for (int i = 1; i <= n; i ++) {
//		cout << a[i] << ' ';
//	}
//	cout << '\n';
//	for (int i = 1; i <= n; i ++) {
//		cout << sum[i] << ' ';
//	}
	int ans = 0;
	for (int i = 1; i <= n; i ++) {
		ans = max(ans, bs(i));
	}
	cout << ans << '\n';
	return 0;
}