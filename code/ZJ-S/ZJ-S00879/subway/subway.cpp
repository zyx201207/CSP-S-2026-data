#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define REP(i, a, b) for(int i = (a); i <= (b); i ++)
#define DOW(i, a, b) for(int i = (a); i >= (b); i --)
#define pii pair<int, int>
#define fi first
#define se second
#define poly vector<int>
#define polyp vector<pii>
#define pb emplace_back
const int N = 5e5 + 5;
long long inf = 1e18;
int fhqAKIOI, n, m, d, q;
int w[N];
polyp e[N];
long long f[1005][1005];
void Solve() {
	cin >> fhqAKIOI >> n >> m >> d >> q;
	REP(i, 1, m) cin >> w[i];
	REP(i, 1, n) { 
		int k; cin >> k;
		REP(j, 1, k) {
			int x, y;
			cin >> x >> y;
			e[x].pb(i + m, y);
		}
	}
	REP(i, 1, n) REP(j, 1, n) f[i][j] = inf;
	REP(i, 1, n) f[i][i] = 0;
	REP(i, 1, m) 
		REP(j, 0, e[i].size() - 1)
			REP(k, j + 1, e[i].size() - 1) {
				pii x = e[i][j], y = e[i][k];
				f[x.fi - m][y.fi - m] = min(f[x.fi - m][y.fi - m], (long long)(x.se + y.se));
			}
	REP(i, 1, n) REP(j, 1, n) f[i][j] = f[j][i] = min(f[i][j], f[j][i]);
	REP(k, 1, n) REP(i, 1, n) REP(j, 1, n)
		f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	REP(i, 1, q) {
		int u, v;
		cin >> u >> v;
		long long ans = w[u] + w[v], r = inf;
		for(auto x : e[u]) for(auto y : e[v])
			r = min(r, f[x.fi - m][y.fi - m] + x.se + y.se);
		cout << r + ans << '\n';
	}
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int T = 1;
//	cin >> T;
	while(T --) {
		Solve();
	}
	return 0;
}
