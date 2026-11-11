#include <bits/stdc++.h>
using namespace std;
long long n, m, a[100005], ans;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = n; i >= 1; i--) {
		long long k = a[i], cnt = 0, p = i;
		for (int j = i - 1; j >= 1; j--) {
			cnt += (k - a[j]);
			if (cnt > m) {
				p = i - j + 1;
				break;
			}
		}
		ans = max(ans, p);
	}
	cout << ans;
	return 0;
}
