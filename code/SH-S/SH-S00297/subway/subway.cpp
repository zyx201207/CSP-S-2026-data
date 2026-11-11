#include <bits/stdc++.h>
using namespace std;
const int MAXN = 505, MAXM = 500005;

int c, n, m, d, q;
long long w[MAXM];
struct road {
	int x;
	long long t;
}st[MAXM][25];
int stc[MAXM];

long long nw[MAXN][MAXN], ans;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1, k, a, t; i <= n; i++) {
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> a >> t;
			st[a][++stc[a]] = {i, t};
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			nw[i][j] = 1E18;
		}
		nw[i][i] = 0;
	}
	for (int i = 1, x, y; i <= m; i++) {
		for (int j = 1; j < stc[i]; j++) {
			for (int k = j + 1; k <= stc[i]; k++) {
				x = st[i][j].x, y = st[i][k].x;
				nw[x][y] = min(nw[x][y], st[i][j].t + st[i][k].t);
				nw[y][x] = nw[x][y];
			}
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				nw[i][j] = min(nw[i][j], nw[i][k] + nw[k][j]);
			}
		}
	}
	for (int i = 1, x, y, u, v; i <= q; i++) {
		cin >> x >> y;
		ans = 1E18;
		for (int j = 1; j <= stc[x]; j++) {
			for (int k = 1; k <= stc[y]; k++) {
				ans = min(ans, st[x][j].t + nw[st[x][j].x][st[y][k].x] + st[y][k].t);
			}
		}
		cout << w[x] + ans + w[y] << '\n';
	}
	
	return 0;
}
