#include <bits/stdc++.h>
#define ll long long
#define N 500010
using namespace std;
int n, m, a[N];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	if (m == 2) {
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		if (a[n] == 1) {
			int ans = 0;
			for (int i = 1; i <= n; ++i) {
				if (a[i] == 2) {
					ans++;
				}
			}
			cout << ans << ' ' << n;
		} else {
			int ans = 0;
			for (int i = 1; i <= n; ++i) {
				if (a[i] == 1) {
					ans++;
				}
			}
			cout << ans << ' ' << n;
		}
		return 0;
	}
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (i != 1 && a[i] != a[i - 1]) {
			cout << i - 1 << ' ';
		}
	}
	cout << n;
	return 0;
}
