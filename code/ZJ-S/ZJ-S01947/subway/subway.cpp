#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#define int long long
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define lop(i, a, b) for (int i = (a); i < (b); i++)
#define dwn(i, a, b) for (int i = (a); i >= (b); i--)
#define mp(a, b) make_pair(a, b)
#define pr pair<int, int>
#define fir first
#define sec second
#define iosfst ios::sync_with_stdio(false);cin.tie(0), cout.tie(0)
using namespace std;
using namespace __gnu_pbds;
const int N = 5e5 + 10, D = 510;
int c, n, m, d, q, w[N], dp[D][D];
vector<int> A[D], P[N];
gp_hash_table<int, int> mp[N];
signed main() {
	iosfst;
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	rep (i, 1, m) cin >> w[i];
	rep (i, 1, n) {
		int k; cin >> k;
		rep (j, 1, k) {
			int a, t; cin >> a >> t;
			A[i].push_back(a);
			P[a].push_back(i);
			mp[a][i] = t;
		}
	}
	rep (i, 1, n) rep (j, 1, n) dp[i][j] = 1e18;
	rep (i, 1, n) {
		lop (j, 0, A[i].size()) {
			int p = A[i][j];//地铁线 i 经过 p  
			int kkk = mp[p][i];//p 到地铁口 i 
			lop (k, 0, P[p].size()) dp[i][P[p][k]] = dp[P[p][k]][i] = min(dp[i][P[p][k]], kkk + mp[p][P[p][k]]);
		}
	}
	rep (i, 1, n) dp[i][i] = 0;
	rep (i, 1, n) rep (j, 1, n) rep (k, 1, n) dp[i][j] = min(dp[i][j], dp[i][k] + dp[j][k]);
	while (q--) {
		int l, r, res = 1e18; cin >> l >> r;
		lop (i, 0, P[l].size()) lop (j, 0, P[r].size()) res = min(res, mp[l][P[l][i]] + mp[r][P[r][j]] + dp[P[l][i]][P[r][j]]);
		cout << res + w[l] + w[r] << '\n';
	}
	return 0;
}

