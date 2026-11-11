#include <bits/stdc++.h>
using namespace std;
long long n, anss, ans;
long long m, a[500005];

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		anss = 0;
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n && k != j; k++) {
				if (m > abs(a[j] - a[k])) {
					anss++;
					m -= abs(a[j] - a[k]);
				}
			}
		}
		ans = max(ans, anss);
	}
	cout << ans + 1;
	return 0;
}