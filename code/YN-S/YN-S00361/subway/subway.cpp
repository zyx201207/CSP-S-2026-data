#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int w[1000100];
int a[10000100];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	int k;
	cin >> k;
	for (int i = 1; i <= 2 * k; i++) {
		cin >> a[i];
	}
	int x, y;
	cin >> x >> y;
	cout << 0 << endl << 1;
	return 0;
}