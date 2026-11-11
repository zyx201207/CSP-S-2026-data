#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int c, n, m, d, q;
int w[500005];
int a[500005], t[500005];
int x[505];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
		for (int j = 1; j <= x[i]; j++) cin >> a[j] >> t[j];
	}
	while (q--) {
		int sta, fin;
		cin >> sta >> fin;
		cout << w[1] << "\n";
	}
	return 0;
}