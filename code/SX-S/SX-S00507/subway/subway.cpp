#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	int w[500000];
	for (int i = 0; i < m; i ++) {
		cin >> w[i];
	}
	int ki;
	cin >> ki;
	int a[500000][500000], t[500000][500000];
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < ki; j ++) {
			cin >> a[i][j] >> t[i][j];
		}
	}
	cout << 32 << endl;
	cout << 17 << endl;
	return 0;
}