#include <bits/stdc++.h>
using namespace std;

long long c, t, ma;
long long n[10], k[10], ans[10], u[10][2000005], v[10][2000005], o[200005], O[200005];

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n[i] >> k[i];
		for (int y = 1; y <= n[i] - 1; y++) {
			cin >> u[i][y] >> v[i][y];
		}
		for (int y = 1; y <= n[i] - 1; y++) {
			o[u[i][y]]++;
			o[v[i][y]]++;
		}
		for (int y = 1; y <= n[i] - 1; y++) {
			ma = max(ma, o[y]);
		}
		ans[i] = n[i] / ma;
	}
	for (int i = t; i >= 1; i--) {
		cout << ans[i] << endl;
	}
	return 0;
}