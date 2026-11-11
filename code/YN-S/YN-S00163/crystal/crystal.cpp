#include <bits/stdc++.h>
using namespace std;
long long n, a[510000], h[510000];
long long ans, b, m, p;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	h[1] = a[1];
	for (int i = 2; i <= n; i++) {
		h[i] = h[i - 1] + a[i];
		if (abs((ans + 1) * a[i] - (h[i - 1] - h[i - ans - 2])) <= m) {
			p = i;
			while (abs(ans * a[i] - (h[i - 1] - h[i - ans - 1])) <= m && i - 1 - ans >= 1) {
				if (abs((ans + 1) * a[i] - (h[i - 1] - h[i - ans - 2])) <= m)
					ans++;
				else {
					break;
				}

			}
		}
	}
	cout << ans + 1 ;
	return 0;
}
