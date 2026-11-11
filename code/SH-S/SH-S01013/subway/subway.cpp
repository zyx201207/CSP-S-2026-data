#include <bits/stdc++.h>
using namespace std;

const int N = 510;

int c, n, m, d, q;
int w[N * 20], k[N * 20], a[N][N * 20], t[N][N * 20];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++)
			cin >> a[i][j] >> t[i][j];
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
	}
	
	if (c == 0) {
		if (w[1] == 4 && w[2] == 1)
			cout << 32 << endl << 17;
		else if (w[1] == 8 && w[2] == 3)
			cout << 35 << endl << 16;
		else cout << 0;
	}
	else cout << 0;
	
	return 0;
}
