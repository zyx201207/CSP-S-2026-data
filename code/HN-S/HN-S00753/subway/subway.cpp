#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 510;
const int M = 5e5 + 10;
int c, n, m, d, q, u, v, w, a[M];
ll ans, f[N][N];
template<int SizV, int SizE>
struct Graph {
	int etot, hd[SizV], prv[SizE], pt[SizE], vl[SizE];
	inline void Add(const int &fm, const int &tt, const int &vlu) {
		prv[++etot] = hd[fm];
		vl[etot] = vlu;
		pt[etot] = tt;
		hd[fm] = etot;
	}
};
Graph<N + M, M << 1> G;
int main()
{
	ios::sync_with_stdio(false) ;
	cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(register int i = 1; i <= m; i ++) cin >> a[i];
	for(register int i = 1; i <= n; i ++) {
		cin >> u;
		while(u --) {
			cin >> v >> w;
			G.Add(i, n + v, w);
			G.Add(n + v, i, w);
		}
	}
	memset(f, 0x3f, sizeof(f));
	for(register int i = 1; i <= n; i ++) f[i][i] = 0;
	for(register int i = 1; i <= n; i ++) {
		for(register int Vi = G.hd[i], V, W; Vi; Vi = G.prv[Vi]) {
			V = G.pt[Vi];
			W = G.vl[Vi];
			for(register int VVi = G.hd[V], VV; VVi; VVi = G.prv[VVi]) {
				VV = G.pt[VVi];
				f[i][VV] = min(f[i][VV], (ll)W + G.vl[VVi]);
			}
		}
	}
	for(register int k = 1; k <= n; k ++) {
		for(register int i = 1; i <= n; i ++) {
			for(register int j = 1; j <= n; j ++) {
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	while(q --) {
		cin >> u >> v;
		ans = LLONG_MAX;
		for(register int Vi = G.hd[n + u], V, W; Vi; Vi = G.prv[Vi]) {
			V = G.pt[Vi];
			W = G.vl[Vi];
			for(register int VVi = G.hd[n + v]; VVi; VVi = G.prv[VVi]) {
				ans = min(ans, f[V][G.pt[VVi]] + W + G.vl[VVi]);
			}
		}
		ans += (a[u] + a[v]);
		cout << ans << '\n';
	}
	return 0;
}
