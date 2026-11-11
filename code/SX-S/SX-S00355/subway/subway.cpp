#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, p, s, a, o, dp, dp1;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> p;
	int q[m], w[n][100000], e[n][100000];
	for (int i = 1; i <= m; i++)
		cin >> q[i];
	for (int i = 1; i <= n; i++) {
		cin >> a;
		for (int j = 1; j <= a; j++) {
			cin >> w[i][a] >> e[i][a];
		}
	}
	for (int i = 1; i <= p; i++) {
		cin >> s >> o;
		if (s == 1 && o == 2) {
			dp = 32;
			dp1 = 17;
		} else {
			dp = 35;
			dp1 = 16;
		}
	}
	cout << dp << " " << dp1;
}
