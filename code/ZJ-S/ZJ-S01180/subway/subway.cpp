#include <iostream>

using namespace std;

const int MAXM = 50001;
const int MAXN = 51;
const int MAXQ = 10001;
int c, n, m, d, q;
int w[MAXM];
int a[MAXN][MAXM];
int t[MAXN][MAXM];
int plan[MAXQ][3];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> a[i][j] >> t[i][j];
		}
	}
	for (int i = 1; i <= q; i++) {
		cin >> plan[i][1] >> plan[i][2];
	}
}