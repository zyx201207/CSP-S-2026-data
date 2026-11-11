#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i = (l); i <= (r); ++i)
#define ROF(i, r, l) for (int i = (r); i >= (l); --i)
#define popc(x) __builtin_popcountll((x))
#define SZ(v) int((v).size())
#define allc(v) (v).begin(), (v).end()
#define PB push_back
#define FI first
#define SE second
#define PII pair<int, int>
#define MP make_pair 
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
template<typename A, typename B>
void chkmax(A &a, B b) { a = (a > b) ? a : b; }
template<typename A, typename B>
void chkmin(A &a, B b) { a = (a < b) ? a : b; } 
bool Mbe;
namespace lyl {
	const int N = 5e2 + 5;
	const int M = 5e5 + 5;
	const ll inf = 1e18;
	int n, m, d, q;
	ll w[M], dis[N][N];
	vector<pair<ll, int>> vec[M], vec2[N];
	void solve() {
		cin >> n >> m >> d >> q;
		FOR (i, 1, m) cin >> w[i];
		FOR (i, 1, n) {
			int k; cin >> k;
			FOR (j, 0, k - 1) {
				int x; ll y; cin >> x >> y;
				vec2[i].PB(MP(y, x));
				vec[x].PB(MP(y, i));
			}
		}
		FOR (i, 1, n) FOR (j, 1, n) dis[i][j] = i == j ? 0 : inf;
		FOR (u, 1, m) {
			FOR (i, 0, SZ(vec[u]) - 1) {
				FOR (j, i + 1, SZ(vec[u]) - 1) {
					ll v = vec[u][i].FI + vec[u][j].FI;
					chkmin(dis[vec[u][i].SE][vec[u][j].SE], v);
					chkmin(dis[vec[u][j].SE][vec[u][i].SE], v);
				}
			}
		}
		FOR (k, 1, n) 
			FOR (i, 1, n) 
				FOR (j, 1, n) 
					chkmin(dis[i][j], dis[i][k] + dis[k][j]);
		FOR (i, 1, q) {
			int u, v; cin >> u >> v;
			ll ans = inf;
			FOR (j, 0, SZ(vec[u]) - 1) {
				FOR (k, 0, SZ(vec[v]) - 1) {
					chkmin(ans, vec[u][j].FI + vec[v][k].FI + dis[vec[u][j].SE][vec[v][k].SE]);
				}
			}
			cout << ans + w[u] + w[v] << '\n';
		}
	}
}
bool Meb;
int main() {
	 freopen("subway.in", "r", stdin);
	 freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int cid; cin >> cid;
	lyl::solve();
//	cerr << "Time: " << clock() * 1000.0 / CLOCKS_PER_SEC << "ms\n"; 
//	cerr << "Space: " << fabs(&Mbe - &Meb) / 1024.0 / 1024.0 << "MB\n";
	return 0;
}
