#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1005 ;
int ta[505];
int biao[N][N];

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	for (int i = 1; i <= c; i++) {
		cin >> ta[i];

	}
	for (int i = 1; i <= b; i++) {
		int nj;
		cin >> nj;
		int guo = 0, zhi = 0;
		for (int i = 1; i <= nj; i++) {
			int n, m;
			cin >> n >> m;
			if (biao[n][guo] != 0 && biao[guo][n] != 0) {
				biao[n][guo] =  min(	biao[n][guo], m + zhi);
				biao[guo][n] =  min(	biao[n][guo], m + zhi);
			} else {
				biao[n][guo] =   m + zhi;
				biao[guo][n] =   m + zhi;

			}

			guo = n;
			zhi = m;
		}
	}

	int sum = 0;
	for (int i = 1; i <= e; i++) {
		int n, m;
		cin >> n >> m;
		sum = 0;
		for (int j = n + 1; j <= m; j++) {
			if (biao[i][m] != 0) {
				sum += biao[i][m];
			} else if (biao[i - 1][i] != 0) {
				sum += biao[i - 1][i];
			}

		}
		cout << sum + ta[n] + ta[m] << "\n";
	}
	return 0;
}
