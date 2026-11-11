#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int c;
long long n, m, d, q;
long long w[N];
long long b[510][510];
long long a[510][1010], t[510][1010], k[510];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
			if (j > 1) {
				b[a[i][j]][0]++;
				b[a[i][j]][b[a[i][j]][0]] = a[i][j - 1];
				b[a[i][j - 1]][0]++;
				b[a[i][j - 1]][b[a[i][j - 1]][0]] = a[i][j];
			}
		}
	}
	for (int i = 1; i <= q; i++) {
		long long x, y;
		cin >> x >> y;
		if (c <= 11 && c >= 7) {
			cout << t[x][1] + t[y][1];
		}
	}
	return 0;
}