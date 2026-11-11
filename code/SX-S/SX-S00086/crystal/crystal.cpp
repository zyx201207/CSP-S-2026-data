#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500005], ans;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (long long i = 1; i <= n; i++) {
		long long y = m;
		for (long long j = i - 1; j >= 1; j--) {
			y = y - (a[i] - a[j]);
			if (y < 0 or j == 1) {
				if (ans < i - j + 1) {
					ans = i - j + 1;
				}
				break;
			}
		}
	}
	cout << ans;
	return 0;
}