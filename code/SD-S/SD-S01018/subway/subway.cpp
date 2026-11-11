// 愿望……和你，在一起

#include <bits/stdc++.h>
#include <cassert>
#define int long long
using namespace std;

bool beginmem_qwq;

constexpr int N = 500100;
constexpr int mod = 998244353;

constexpr int inf = 2e18;

inline int power(int a, int b, int c) {
	int res = 1; while (b) {
		if (b & 1) res = res * a % c;
		a = a * a % c, b >>= 1;
	} return res;
}

inline int inversion(int x) {
	return power(x, mod - 2, mod);
}

using u8 = unsigned char;

using i16 = short;
using u16 = unsigned short;

using u32 = unsigned;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;

namespace Solver {
	
	int a[N], pre[N];
	
	inline void init() {
		
	}
	
	struct Subway {
		int k;
		vector<int> a, t;
	} subway[N];
	
	int mp[510][510], w[N];
	vector<pair<int, int>> buc[N] ;
	
	// mp[i][j] : 从地铁 i 走到地铁 j 所需要花费的最少走路时间是多少 
	
	inline void sol() {
		int c, n, m, d, q; cin >> c >> n >> m >> d >> q;
		for (int i = 1; i <= m; ++i) cin >> w[i];
		for (int i = 1; i <= n; ++i) {
			cin >> subway[i].k;
			subway[i].a.resize(subway[i].k, 0);
			subway[i].t.resize(subway[i].k, 0);
			for (int j = 1; j <= subway[i].k; ++j) {
				cin >> subway[i].a[j - 1] >> subway[i].t[j - 1];
				buc[subway[i].a[j - 1]].emplace_back(i, subway[i].t[j - 1]);
			}
		}
		memset(mp, 0x3f, sizeof mp);
		for (int i = 1; i <= n; ++i) mp[i][i] = 0;
		for (int i = 1; i <= m; ++i)
			for (int j = 0; j < buc[i].size(); ++j)
				for (int k = j + 1; k < buc[i].size(); ++k)
					mp[buc[i][j].first][buc[i][k].first] = mp[buc[i][k].first][buc[i][j].first] = min(mp[buc[i][j].first][buc[i][k].first], buc[i][j].second + buc[i][k].second);
		for (int k = 1; k <= n; ++k)
			for (int i = 1; i <= n; ++i)
				for (int j = 1; j <= n; ++j)
					mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
		while (q--) {
			int x, y; cin >> x >> y;
			if (x == y) cout << 0 << '\n';
			else {
				int res = inf;
				for (int i = 0; i < buc[x].size(); ++i)
					for (int j = 0; j < buc[y].size(); ++j)
						res = min(res, mp[buc[x][i].first][buc[y][j].first] + buc[x][i].second + buc[y][j].second);
				cout << res + w[x] + w[y] << '\n';
			}
		}
	}
}

inline void calc_forever1210();

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);
	int T = 1;
//	cin >> T;
	Solver::init();
	while (T--) {
		Solver::sol();
	}
	calc_forever1210();
	return 0;
}

bool endmem_qwq;

inline void calc_forever1210() {
	cerr << fixed << setprecision(5);
//	cerr << "Memory Used " << abs(&beginmem_qwq - &endmem_qwq) / 1048576. << " MB.\n";
}

