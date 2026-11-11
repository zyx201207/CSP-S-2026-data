#include <bits/stdc++.h>
using namespace std;
long long n, m, ans, t;
long long a[500005], d[50005];
bool k;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		d[i] = a[i] - a[i - 1];
	}
	for (int i = 1; i <= n; i++) {
		t = 0;
		for (long long j = 0;; j++) {
			t += d[i + j] * j;
			if (t > m) {
				ans = max(ans, j );
				break;
			}
			if (i + j == n) {
				ans = max(ans, j + 1);
				k = 1;
				break;
			}
		}
		if (k) {
			break;
		}
	}
	cout << ans;
	return 0;
}