#include <bits/stdc++.h>
using namespace std;
long long n, m, x[123456], cnt, ans;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
		cnt = max(cnt, x[i]);
		ans = min(ans, x[i])
	}
	sort(x + 1, x + n + 1);
	if (m == 1) {
		cout << cnt;
		return 0;
	}
	cnt = 0;
	if (m == n || m == n - 1) {
		cout << ans;
		return 0;
	}
	ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int q = i, t = i + 1; t <= n; t++) {
			int a = x[q], b = x[t];
			for (int w = log2(max(x[q], x[t])); w >= 0; w--) {
				if (long(pow(2, w)) < a && long(pow(2, w)) < b) {
					cnt += long(pow(2, w))
					       a -= long(pow(2, w));
					b -= long(pow(2, w));
				}
			}
			ans = max(ans, cnt);
			cnt = 0;
		}
	}
	cout << cnt;
	return 0;
}