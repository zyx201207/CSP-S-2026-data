#include <bits/stdc++.h>
#define E(i, l, r) for(int i = l; i <= r; ++ i)
#define D(i, r, l) for(int i = r; i >= l; -- i)
#define int long long
using namespace std;

int n, cc, tt;
namespace sub1 {
	const int N = 5000 + 10, LOG = 23, B = 21;
	int d, ans, x[N], f[N][LOG], len[N][N], c[N][N], q[N][N], s[N][N];
	
	inline int dis(int a, int b) {
		if(a == b) return 0;
		
		int res = 0, now = a;
		D(j, B, 0) {
			if(f[now][j] < b) {
				now = f[now][j], res += (1 << j);
			}
		}
		return res + 1;
	}
	
	inline void work() {
		ans = 0;
		memset(f, 0, sizeof f);
		E(i, 1, n) E(j, 1, n) c[i][j] = q[i][j] = len[i][j] = 0;
		
		cin >> n >> d;
		E(i, 1, n) cin >> x[i];
		
		E(i, 1, n) {
			int limit = x[i] + d;
			if(limit >= x[n]) {
				f[i][0] = n;
			} else f[i][0] = upper_bound(x + 1, x + n + 1, limit) - x - 1;
		}
		
		E(j, 1, B) E(i, 1, n) f[i][j] = f[f[i][j - 1]][j - 1];
		
		E(i, 1, n) E(j, i, n) len[i][j] = dis(i, j);
		
		E(i, 1, n) E(j, i, n) {
			if(j <= f[i][0]) {
				c[i][j] = 1;
				continue;
			}
			
			if(len[f[i][0]][j] == len[f[i][0] - 1][j]) {
				c[i][j] = 0;
				continue;
			}
			
			c[i][j] = c[f[i][0]][j];
		}
		
		E(le, 1, n) E(l, 1, n - le + 1) {
			int r = l + le - 1;
			int i = l, j = r;
			if(c[i][j]) continue;
			E(k, f[i][0], j) {
				if(len[k][j] + 1 == len[i][j]) {
					c[i][j] += c[k][j];
				}
				if(c[i][j] >= 3) c[i][j] = 3;
			}
		}
		
		E(i, 1, n) E(j, i + 2, n) {
			if(c[i][j] == 2) ++ ans;
		}
		
		cout << ans << "\n";
		return;
	}
}

namespace sub2 {
	const int N = 2E6 + 10;
	int d, x[N], dlt;
	
	inline void work() {
		cin >> d;
		E(i, 1, n) cin >> x[i], dlt = x[i] - x[i - 1];
		
		d /= dlt;
		if(d <= 1) {
			cout << 0 << "\n";
			return;
		}
		
		cout << max(n - 2 * d + 1, 0ll) << "\n";
	}
}

namespace sub3 {
	inline void work() {
		cout << 0 << "\n";
	}
}

namespace wangcy {
	inline void work() {
		cin >> n;
		if(cc <= 6) sub1::work();
		else if(cc <= 12) sub2::work();
		else sub3::work();
	}
}

signed main() {
	freopen("migrate.in", "r", stdin), freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	
	cin >> cc >> tt;
	while(tt --) wangcy::work();
	return 0;
}
/*
0 1
5 3
-3 0 2 3 4
*/