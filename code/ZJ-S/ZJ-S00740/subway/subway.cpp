#include <bits/stdc++.h>
#define FL(i, a, b) for (int i = (a); i <= (b); ++i)
#define FR(i, a, b) for (int i = (a); i >= (b); --i)
#define fi first
#define se second
#define eb emplace_back
#define Sz(v) ((int)(v).size()) 
using namespace std;
typedef long long ll;
typedef pair<int, int> Pii;
const int N = 5e5 + 10;
const int M = 510; 
const int INF = 2e9 + 10;
const ll INFLL = 1e18 + 10;
int Cid, n, m, d, q, e[M][M];
ll w[N], f[M][M];

int k[N], vis[N];
int tot, l[N], r[N], pos[N], val[N];

vector<Pii> G[N];

template<typename T>
inline void ChkMin(T &x, T y) {
	if (y < x) x = y;
}
int main() {
//	freopen("subway1.in", "r", stdin);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0); 
	cin >> Cid >> n >> m >> d >> q; 
	FL(i, 1, m) cin >> w[i];
	FL(i, 1, n) {
		cin >> k[i];
		l[i] = tot + 1, r[i] = tot + k[i];
		FL(j, l[i], r[i]) {
			cin >> pos[j] >> val[j];
			G[pos[j]].eb(i, val[j]);
		}
		tot += k[i];
	}
	FL(i, 1, n) {
		FL(j, l[i], r[i]) {
			vis[pos[j]] = val[j];
		}
		FL(t, i + 1, n) {
			e[i][t] = INF;
			FL(j, l[t], r[t]) if (vis[pos[j]]) {
				ChkMin(e[i][t], vis[pos[j]] + val[j]);
			}
		}
		FL(j, l[i], r[i]) {
			vis[pos[j]] = 0;
		}
	}
	FL(i, 1, n) FL(j, 1, n) {
		if (i == j) f[i][j] = 0;
		else if (i > j) f[i][j] = (e[j][i] == INF? INFLL : e[j][i]);
		else f[i][j] = (e[i][j] == INF? INFLL : e[i][j]);
	}
	FL(p, 1, n) FL(i, 1, n) FL(j, 1, n) {
		ChkMin(f[i][j], f[i][p] + f[p][j]);
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		ll ans = INFLL;
		for (Pii a: G[x]) {
			for (Pii b: G[y]) {
				ChkMin(ans, f[a.fi][b.fi] + a.se + b.se);
			} 
		}
		ans += w[x] + w[y];
		cout << ans << '\n';
	}
	return 0;
}
// check [a, b]
// duipai, jiancha, check dayangli
