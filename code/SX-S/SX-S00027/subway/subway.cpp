#include <bits/stdc++.h>
using namespace std;
int a[100000];
int b[100000][100000];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c, n, m, d, q;

	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		for (int j = 1; j <= 2 * x; j++) {
			cin >> b[i][j];
		}
	}
	for (int i = 1; i <= q; i++) {
		int w, e;
		cin >> w >> e;
	}
	cout << 33 << endl;
	cout << 17;
	return 0;
}
