// gaoxuke xajdfz SN-S00361
#include <bits/stdc++.h>
using namespace std;

namespace gxk {
	void main() ;
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	gxk::main();
	return 0;
}

// ---

#define int long long
#define rep(x, l, r) for (int x = (l); x <= (r); x++)
#define per(x, r, l) for (int x = (r); x >= (l); x--) 

namespace Maky {
	template <typename T> inline void chkmin(T &x, T y) {
		x = (x < y ? x : y);
		return ;
	}
	template <typename T> inline void chkmax(T &x, T y) {
		x = (x > y ? x : y);
		return ;
	}
} using namespace Maky;

namespace gxk {
	constexpr int maxn = 2000010;
	
	int C, T, n, d, a[maxn], r[maxn], f[maxn], l[maxn], mp[maxn];
	
	inline void ins(int l, int r, int v) {
		if (r > l && v) {
			mp[r] += v;
		}
		return ;
	}
	inline int ask(int l, int r, int v) {
		if (r <= l || !v) return 0;
		return mp[l + 1] * v;
	}
	
	void main() {
		cin >> C >> T;
		while (T--) {
			cin >> n >> d;
			rep (i, 1, n) cin >> a[i];
			int nowr = 1;
			rep (i, 1, n) {
				f[i] = 0;
				while (nowr < n && a[nowr + 1] - a[i] <= d) nowr++;
				r[i] = nowr;
			}
			rep (i, 1, n) {
				ins(i + 1, r[i], 1);
				if (i > 1) ins(r[i - 1] + 1, r[i], f[i]);
				if (i == 1) f[r[i]] += f[i];
				else if (r[i - 1] != r[i]) f[r[i]] += f[i];
				f[r[i]]++;
			}
			
			int nowl = n;
			per (i, n, 1) {
				f[i] = 0;
				while (nowl > 1 && a[i] - a[nowl - 1] <= d) nowl--;
				l[i] = nowl;
			}
			int ans = 0;
			per (i, n, 1) {
				ans += ask(l[i], i - 1, 1);
				if (i < n) ans += ask(l[i], l[i + 1] - 1, f[i]);
				if (i == n) f[l[i]] += f[i];
				else if (l[i + 1] != l[i]) f[l[i]] += f[i];
				f[l[i]]++;
			}
			
			cout << ans << '\n';
			
			rep (i, 1, n) mp[i] = 0;
		}
		
		return ;
	}
}
