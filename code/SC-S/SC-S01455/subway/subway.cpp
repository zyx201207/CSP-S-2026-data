#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IL inline
#define FIO(name) freopen(name".in", "r", stdin), freopen(name".out", "w", stdout)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define lop(i, a, b) for (auto i = (a); i <= (b); i++)
#define pol(i, a, b) for (auto i = (a); i >= (b); i--)
#define asmax(a, b) ((a) = max((a), (b)))
#define asmin(a, b) ((a) = min((a), (b)))
#define fst first
#define snd second
const int N = 505, M = 5e5 + 5;
int subid, n, m, d, q;
ll h[M], a[M], b[M], G[N][N];
//vector<pair<int, ll>> mp[]
int main () {
	FIO("subway");
	IOS;
	cin >> subid >> m >> n >> d >> q;
	lop(i, 1, n) cin >> h[i];
	memset(G, 0x3f, sizeof G);
	lop(u, 1, m) {
		int k; cin >> k;
		lop(i, 1, k) cin >> a[i] >> b[i];
		lop(i, 1, k) lop(j, 1, k) {
			int iv = a[i], jv = a[j];
			if (iv != jv) {
				if (G[iv][jv] >= 4e18) G[iv][jv] = 0;
				if (G[jv][iv] >= 4e18) G[jv][iv] = 0;
				G[iv][jv] += b[i], G[jv][iv] += b[i];
			}
		}
	}
//	lop(i, 1, n) lop(j, 1, n) cout << (G[i][j] > 1e18 ? -1 : G[i][j]) << " \n"[j == n];
	lop(k, 1, n) lop(i, 1, n) lop(j, 1, n) asmin(G[i][j], G[i][k] + G[k][j]);
	while (q--) {
		int s, t; cin >> s >> t;
//		dijkstra(s);
//		lop(i, 1, n) lop(j, 1, n) cout << (G[i][j] > 1e18 ? -1 : G[i][j]) << " \n"[j == n];
		cout << G[s][t] + h[s] + h[t] << '\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/