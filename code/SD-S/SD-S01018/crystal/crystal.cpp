// 愿望……和你，在一起

#include <bits/stdc++.h>
#define int long long
using namespace std;

constexpr int N = 1000100;
constexpr int mod = 998244353;

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
	
	inline void sol() {
		int n ,m; cin >> n >> m;
		for (int i = 1; i <= n; ++i) cin >> a[i];
		sort(a + 1, a + n + 1);
		int res = 1;
		for (int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + a[i];
		for (int i = 2; i <= n; ++i) {
			int l = 1, r = i - 1, best = i;
			while (l <= r) {
				int mid = l + r >> 1;
				int o = a[i] * (i - mid + 1) - pre[i] + pre[mid - 1];
				if (o <= m) best = mid, r = mid - 1;
				else l = mid + 1;
			}
			res = max(res, i - best + 1);
		}
		cout << res << '\n';
	}
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);
	int T = 1;
//	cin >> T;
	Solver::init();
	while (T--) {
		Solver::sol();
	}
	return 0;
}
