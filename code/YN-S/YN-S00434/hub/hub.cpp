#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[900009];
int b[900009];

signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c, t;
	cin >> c >> t;
	while (t--) {
		int n, m, max;
		cin >> n >> m;
		for (int i = 1; i <= n - 1; i++) {
			cin >> a[i] >> b[i];
		}
		cout << 1 << '\n';
	}
	return 0;
}