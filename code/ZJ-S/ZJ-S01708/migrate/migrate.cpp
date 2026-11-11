#include <bits/stdc++.h>
#define int long long
#define F(i, a, b) for (int i = (a); i <= (b); ++i)
#define D(i, a, b) for (int i = (a); i >= (b); --i)
#define sz(x) ((int)x.size())
#define pb push_back
#define FIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MLE cerr<<fabs(&Med-&Mbe)/1048576.0<<"MB\n";
using namespace std;
const int N = 2e6 + 5, inf = 1e14;
bool Mbe;
int C, n, d, a[N];
namespace sol_1_6 {
	int f[5005][5005], g[5005][5005];
	void mian() {
		F(i, 1, n) F(j, i + 1, n) {
			f[i][j] = inf, g[i][j] = 0;
			if (a[j] - a[i] <= d) f[i][j] = g[i][j] = 1;
		}
		F(k, 1, n) {
			F(i, 1, k - 1) if (f[i][k] != inf) {
				F(j, k + 1, n) if (f[k][j] != inf) {
					if (f[i][j] == inf || f[i][k] + f[k][j] < f[i][j]) {
						f[i][j] = f[i][k] + f[k][j];
						if (g[i][k] == -1 || g[k][j] == -1) g[i][j] = -1;
						else g[i][j] = g[i][k] * g[k][j];
						if (g[i][j] > 2) g[i][j] = -1;
					} else if (f[i][k] + f[k][j] == f[i][j]) {
						if (g[i][j] != -1) {
							g[i][j] += g[i][k] * g[k][j];
							if (g[i][j] > 2) g[i][j] = -1;
						}
					}
				}
			}
		}
		int ans = 0;
		F(i, 1, n) F(j, i + 1, n) if (g[i][j] == 2) ++ans;
		cout << ans << '\n';
	}
}
void sol_11_12() {
	int dd = a[2] - a[1];
	int x = d / dd;
	if (x <= 1) cout << "0\n";
	else cout << max(0ll, n - (2 * x - 1)) << '\n';
}
void sol_13_14() {
	int p = 1;
	F(i, 1, n) {
		if (a[i] - a[1] <= d && a[n] - a[i] <= d) {
			p = i;
			break;
		}
	}
	if (p == 1 || p == n) {
		cout << "0\n";
		return;
	}
	int lx = 0, rx = 0, ly = 0, ry = 0;
	F(i, 1, p - 1) {
		if (a[p] - a[i] <= d && a[p + 1] - a[i] > d) {
			++lx;
		} else if (a[p + 1] - a[i] <= d && (p + 2 > n || a[p + 2] - a[i] > d)) {
			++ly;
		}
	}
	F(i, p + 1, n) {
		if (a[i] - a[p] <= d && a[i] - a[p - 1] > d) {
			++rx;
		} else if (a[i] - a[p - 1] <= d && (p - 2 < 1 || a[i] - a[p - 2] > d)) {
			++ry;
		}
	}
	cout << lx * ry + rx * ly << '\n';
}
void sol() {
	cin >> n >> d;
	F(i, 1, n) cin >> a[i];
	if (n == 1) {
		cout << "0\n";
		return;
	}
	if (C == 11 || C == 12) {
		sol_11_12();
		return;
	}
	if (C == 13 || C == 14) {
		sol_13_14();
		return;
	}
	sol_1_6::mian();
	return;
}
bool Med;
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	FIO
	int T = 1; cin >> C >> T;
	while (T--) sol();
//	MLE;
	return 0;
}
/*
12 3
4 2
1 2 3 4
5 2
1 2 3 4 5
5 3
-2 -1 0 1 2

1
2
0

11 1
10 22
0 7 14 21 28 35 42 49 56 63

13 1
5 3
1 3 4 5 6
*/
