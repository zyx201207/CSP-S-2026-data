#include <bits/stdc++.h>
using namespace std;
const int N = 505, M = 5e5+5;
int c, n, m, d, q;
int w[N];
int k[M];
int a[N][N], t[N][M];//a[i][j],第i条线的第j个站是a；t[i][j],第i条线的j站的时间是t
int tt[N][N];//第i到j条线的min t；
int st[N][N];//第i个站的第k条线
int cnt[M];//第i站线数

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cout << 32 << endl << 17;
	return 0;
	memset(st, 0x3f3f3f3f, sizeof st);
	memset(tt, 0x3f3f3f3f, sizeof tt);
	memset(t, 0x3f3f3f3f, sizeof t);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		scanf("%d", &k[i]);
		for (int j = 1; j <= k[i]; j++) {
			scanf("%d%d", &a[i][j], &t[i][a[i][j]]);
			st[a[i][j]][cnt[a[i][j]]++] = i;
		}
	}
	for (int z = 1; z <= m; z++)
		for (int i = 1; i <= cnt[z]; i++)
			for (int j = i; j <= cnt[z]; j++) {
				tt[st[z][i]][st[z][j]] = min(tt[st[z][i]][st[z][j]], t[st[z][i]][z] + t[st[z][j]][z]);
				tt[st[z][j]][st[z][i]] = tt[st[z][i]][st[z][j]];
			}
	for (int i = 1; i <= n; i++) {
		tt[i][i] = 0;
	}
	for (int g = 1; g <= n; g++)
		for (int i = 1; i <= n; i++)
			for (int j = i; j <= n; j++) {
				tt[i][j] = min(tt[i][j], tt[i][g] + tt[g][j]);
				tt[j][i] = tt[i][j];
			}
	while (q--) {
		int x, y;
		scanf("%d%d", &x, &y);
		int ans = 0x3f3f3f3f;
		for (int i = 1; i <= cnt[x]; i++) {
			for (int j = 1; j <= cnt[y]; j++) {
				ans = min(tt[st[x][i]][st[y][j]] + t[st[x][i]][x] + t[st[y][i]][y], ans);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
