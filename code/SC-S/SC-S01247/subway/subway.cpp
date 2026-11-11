#include <bits/stdc++.h>
#define E(i, l, r) for(int i = l; i <= r; ++ i)
#define D(i, r, l) for(int i = r; i >= l; -- i)
#define int long long
using namespace std;

const int N = 505, M = 5E5 + 10, inf = 1E18;
using P = pair <int, int>;

int cc, n, m, d, q, w[M], f[N][N];
map <P, int> t;
vector <P> plt[M];

signed main() {
	freopen("subway.in", "r", stdin), freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> cc >> n >> m >> d >> q;
	E(i, 1, m) cin >> w[i];
	
	E(i, 1, n) E(j, 1, n) f[i][j] = inf;
	E(i, 1, n) f[i][i] = 0;
	
	E(i, 1, n) {
		int k = 0;
		cin >> k;
		E(j, 1, k) {
			int pos = 0, t = 0;
			cin >> pos >> t;
			for(P tmp: plt[pos]) {
				int _pos = tmp.first, _t = tmp.second;
				f[i][_pos] = min(f[i][_pos], t + _t);
				f[_pos][i] = min(f[_pos][i], t + _t);
			}
			plt[pos].emplace_back(make_pair(i, t));
		}
	}
	
	E(k, 1, n) E(i, 1, n) E(j, 1, n) f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	
	while(q --) {
		int u = 0, v = 0, ans = inf;
		cin >> u >> v;
		for(P s: plt[u]) for(P t: plt[v]) {
			ans = min(ans, f[s.first][t.first] + s.second + t.second);
		}
		cout << ans + w[u] + w[v] << "\n";
	}
	
	return 0;
}