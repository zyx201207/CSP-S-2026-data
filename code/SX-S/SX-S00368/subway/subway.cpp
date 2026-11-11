#include <bits/stdc++.h>
typedef long long ll;
const int N = 5e5+10;
int g[N][N], w[N];
int c, n, m, d, q;
using namespace std;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; i++) {
			int a, b;
			cin >> a >> b;
			g[i][a] = b;
		}
	}
	return 0;
}