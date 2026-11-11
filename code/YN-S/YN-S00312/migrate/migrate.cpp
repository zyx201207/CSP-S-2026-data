#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6;
int a[N];

signed main() {
freopen("migrate.in", "r", stdin);
freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int c, n;
	cin >> c >> n;
	for (int i = 1; i <= n; i++) {
		int nn, m;
		cin >> nn >> m;
		for (int i = 1; i <= nn; i++) {
			cin >> a[i];
		}
		sort(a + 1, a + 1 + n);
		int l = 1, r = l + m + 1;
		int sum = 0;
		while (r <= nn) {
			sum++;
			l++, r++;

		}
		cout << sum << "\n";
	}
	return 0;
}
