#include<bits/stdc++.h>
#define cs const
#define LL long long
#define pil pair<int, LL>
#define fs first
#define sc second

using namespace std;

cs int MAXN = 500 + 7;
cs int MAXM = 5e5 + 7;
cs LL INF = 0x3f3f3f3f3f3f3f3f;

int c, n, m, d, q, x, y;
LL entry[MAXM];
vector<pil> line[MAXM];
LL f[MAXN][MAXN];

int main() {
#ifndef DEBUG
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
#endif
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i)	cin >> entry[i];
	for (int i = 1, k, ind, t; i <= n; ++i) {
		cin >> k;
		for (int j = 1; j <= k; ++j)
			cin >> ind >> t, line[ind].push_back({i, t});
	}
	memset(f, 0x3f, sizeof(f));
	for (int i = 1; i <= n; ++i)	f[i][i] = 0;
	for (int i = 1; i <= m; ++i) {
		int siz = line[i].size();
		for (int j = 0; j < siz; ++j)
			for (int k = j + 1; k < siz; ++k) {
				pil ff = line[i][j], tt = line[i][k];
				f[ff.fs][tt.fs] = min(f[ff.fs][tt.fs], ff.sc + tt.sc);
				f[tt.fs][ff.fs] = f[ff.fs][tt.fs];
			}
	}
	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j)
			for (int k = 1; k <= n; ++k) {
				if (f[i][k] == INF || f[j][k] == INF)	continue;
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
				f[j][i] = f[i][j];
			}
	while (q--) {
		cin >> x >> y;
		LL ans = INF;
		for (cs pil& st : line[x])
			for (cs pil& ed : line[y])
				ans = min(ans, f[st.fs][ed.fs] + st.sc + ed.sc);
		cout << (ans + entry[x] + entry[y]) << '\n';
	}
	return 0;
}