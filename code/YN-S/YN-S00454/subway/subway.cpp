#include <bits/stdc++.h>
using namespace std;
#define int long long

struct point {
	int dw, t;
};
int c, n, num, m, d, q, s, e, ans;
int md[401][401][21], f[1100], b[201][401][3];
queue<point> dl;

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> f[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> num;
		for (int j = 1; j <= num; j++) {
			cin >> b[i][j][1];
		}
		for (int j = 1; j <= num; j++) {
			cin >> b[i][b[i][j][1]][2];
		}
		for (int j = 1; j < num; j++) {
			for (int k = j + 1; k <= num; k++) {
				md[j][k][i] = md[k][j][i] = 1;
			}
		}
	}
	for (int i = 1; i <= q; i++) {
		ans = 2147483648;
		cin >> s >> e;
		while (!dl.empty()) {
			dl.pop();
		}
		dl.push({s, f[s] + f[e]});
		while (!dl.empty()) {
			point now = dl.front();
			dl.pop();
			int nowdw = now.dw;
			int nowt = now.t;
			if (nowdw == e) {
				ans = min(ans, nowt);
			}
			for (int i = 1; i <= m; i++) {
				if (i == nowdw) {
					continue;
				}
				for (int j = 1; j <= n; j++) {
					if (md[nowdw][i][j] != 0) {
						dl.push({j, nowt + b[j][nowdw][2] + b[j][i][2]});
					}
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}