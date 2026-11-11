#include <bits/stdc++.h>
using namespace std;
int c, t;
int n, m, cnt;
const int N = 2e6 + 5;
int a[N];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while (t--) {
		cin >> n >> m;
		cnt = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for (int i = 1; i <= n - 3; i++) {
			int l = i, r = i + 3;
			if (a[r] - a[l] > m && a[r] - a[l] < 2 * m && a[i + 2] - a[i] <= m) {
				cnt++;
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}