// 愿望……和你，在一起 

#include <bits/stdc++.h>
#include <cassert>
#define int long long
using namespace std;

bool beginmem_qwq;

constexpr int N = 2000100;
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
	
	int cccc;
	
	inline void init() {
		
	}
	
	int f[N], g[N], st[N][20], lim[N], maxlen[N], dp[N], dp2[N], x[N], gp[N];
	// st[i][j] : 从 i 位置跳 2^j 个 f 到达的位置 
	// lim[i] : 从 i 开始向右跳 最远可以跳到哪里 
	// maxlen[i] : 从 i 位置开始往右跳 最远最少跳多少步 
	// dp2[i] : 从起点到 i 位置 最少需要走多少步 
	
	inline void sol() {
		int n, d; cin >> n >> d;
		for (int i = 1; i <= n; ++i) cin >> x[i];
		int res = 0;
		for (int i = 0; i <= n + 1; ++i) f[i] = g[i] = lim[i] = -1;
		lim[n] = n;
		for (int i = n - 1; i; --i)
			if (x[i + 1] - x[i] > d) lim[i] = i;
			else lim[i] = lim[i + 1];
		for (int i = 1; i < n; ++i) {
			int l = i + 1, r = n, best = -1;
			while (l <= r) {
				int mid = l + r >> 1;
				if (x[mid] - x[i] <= d) best = mid, l = mid + 1;
				else r = mid - 1;
			} if (~best) {
				f[i] = best;
				if (best != i + 1) g[i] = f[i] - 1;
			} else f[i] = i;
		} f[n] = n;
		for (int i = 1; i <= n; ++i) {
			int l = 1, r = i - 1, best = i;
			while (l <= r) {
				int mid = l + r >> 1;
				if (x[i] - x[mid] <= d) best = mid, r = mid - 1;
				else l = mid + 1;
			} gp[i] = best;
		}
		if (n <= 5000) {
			for (int i = 1; i < n - 2; ++i) {
				if (lim[i] < i + 3) continue;
				for (int j = 0; j <= n + 1; ++j) dp[j] = 0, dp2[j] = inf;
				dp[i] = dp[i + 1] = 1;
				dp2[i] = 0, dp2[i + 1] = 1;
				int start = -1;
				for (int j = i + 2; j <= lim[i]; ++j)
					if (x[j] - x[i] > d) {
						start = j;
						break;
					} else dp[j] = 1, dp2[j] = 1;
				if (!~start) continue;
				for (int j = start; j <= lim[i]; ++j) {
					int can = gp[j];
	//				int can = j;
	//				for (int k = j - 1; k >= i; --k) {
	//					if (x[j] - x[k] > d) break;
	//					can = k;
	//				}
					assert(can != j);
					dp2[j] = dp2[can] + 1, dp[j] = 0;
					for (int k = can; k <= min(j - 1, can + 2); ++k) {
						if (dp2[can] == dp2[k]) {
							dp[j] += dp[k];
	//						assert(k == can);
							if (dp[j] > 2) {
								dp[j] = 3;
								break;
							}
						}
					}
	//				cerr << "!!! " << i << ' ' << j << ' ' << dp[j] << "   ";
	//				for (int k = i ;k <= j; ++k) cerr << dp2[k] << ' '; cerr << '\n';
					if (dp[j] == 2) ++res;
				}
			} cout << res << '\n';
		} else {
			int ok = 1;
			for (int i = 2; i <= n; ++i)
				ok &= (x[i] - x[i - 1] == x[2] - x[1]);
			if (ok) {
//				cerr << "@@@@@@\n";
				// Sub A
				if (x[n] - x[1] <= d || x[3] - x[1] > d) cout << 0 << '\n';
				else {
					int maxjmp = 2;
					while (1) {
						if (x[maxjmp + 2] - x[1] > d) break;
						++maxjmp;
					} assert(x[maxjmp + 1] - x[1] <= d);
					assert(x[maxjmp + 2] - x[1] > d);
					int res = 0;
					maxjmp = maxjmp * 2 - 1;
					for (int i = 1, j = maxjmp + 1; j <= n; ++i, ++j)
						++res;
					cout << res << '\n';
				}
			} else {
				// Sub B
				// no wo mei xie wan /ll
				int res = 0;
				vector<int> vec;
				for (int i = 1; i <= n; ++i)
					if (x[i] - x[1] <= d && x[n] - x[i] <= d)
						vec.emplace_back(i);
				assert(vec.size());
				int L = vec[0], R = vec.back();
				if (R - L + 1 > 2) cout << 0 << '\n';
				else {
					if (L == 1 || R == n) {
						cout << 0 << '\n';
						return;
					}
					if (L == R) {
						int res = 0;
						// 1. 恰好能走 L-1 和 L 连通 
//						do {
//							if (L == 2) break;
//							int cnt = 0;
//							for (int i = L + 1; i <= n; ++i)
//								if (x[i] - x[L - 1] <= d && x[i] - x[L - 2] > d) ++cnt;
//							
//						} while (0);
						// 2. 恰好能走 L 和 L+1 连通 
						res = 1;
						cout << res << '\n';
					} else {
						int p1 = 0, p2 = 0;
						for (int i = 1; i <= n; ++i)
							if (x[R + 1] - x[i] <= d) {
								p1 = i - 1;
								break;
							}
						for (int i = n; i; --i)
							if (x[i] - x[L - 1] <= d) {
								p2 = i + 1;
								break;
							}
						cout << p1 * (n - p2 + 1) << '\n';
					}
				}
			}
		}
//		// f[i] : 从 i 开始出发可以到达的最远点 
//		// g[i] : 从 i 开始出发可以到达的次远点 
//		// 若为 -1 则表示没有对应的点呃 
//		
//		// L[i] : 从 i 开始出发，走恰好一个 g，最近到哪里可以匹配上 
//		
//		int res = 0;
//		for (int i = 0; i <= n + 1; ++i) L[i] = inf;
//		for (int i = 1; i <= n; ++i)  {
//			if (~f[i]) st[i][0] = f[i];
//			else st[i][0] = n + 1;
//		} for (int i = 1; i < 20; ++i)
//			for (int j = 1; j <= n; ++j)
//				st[j][i] = st[st[j][i - 1]][i - 1];
//		for (int i = 1; i <= n; ++i) {
//			int cnt = 0, pos = i;
//			for (int j = 19; ~j; --j)
//				if (st[pos][j] != lim[i]) cnt |= (1 << j), pos = st[pos][j];
//			if (lim[i] != i) maxlen[i] = cnt + 1;
//			else maxlen[i] = 0;
//		}
//		for (int i = 1; i < n; ++i) {
//			// 枚举在 i 位置跳一次 g 边
//			if (~g[i]) {
//				int x = f[i], y = g[i], cnt = 0;
//				for (int j = 19; ~j; --j)
//					if (st[x][j] != st[y][j])
//						x = st[x][j], y = st[y][j], cnt |= (1 << j);
//				if (st[y][0] != x && st[x][0] == st[y][0]) L[i] = st[x][0];
//			}
//		}
//		for (int i = n; ~i; --i) L[i] = min(L[i], L[i + 1]);
//		// L[i] : i 第一次可以成为答案的位置 
//		for (int i = 1; i <= n - 3; ++i) {
//			for (int j = i + 3; j <= n; ++j) {
//				
//			}
//		}
	}
}

inline void calc_forever1210();

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin >> Solver::cccc;
	int T = 1;
	cin >> T;
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

