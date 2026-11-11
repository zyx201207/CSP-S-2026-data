#include <bits/stdc++.h>
using namespace std;
const int N = 510;
const int K = 5e5 + 10;
const int M = 5e5 + 10;
int c, n, m, d, q;
int w[M];
int a[N][K];
int t[N][K];
int s, e;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j] >> t[i][j];
		}

	}
	cin >> s >> e;

	return 0;
}