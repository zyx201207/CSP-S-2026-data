// gaoxuke xajdfz SN-S00361
#include <bits/stdc++.h>
using namespace std;

namespace gxk {
	void main() ;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
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
	constexpr int maxn = 500010;
	
	int n, m, a[maxn], sum[maxn];
	
	void main() {
		cin >> n >> m;
		rep (i, 1, n) cin >> a[i];
		sort(a + 1, a + 1 + n);
		rep (i, 1, n) sum[i] = sum[i - 1] + a[i];
		int ans = 0;
		rep (i, 1, n) {
			int l = 0, r = i - 1;
			while (l <= r) {
				int mid = (l + r) / 2;
				if (a[i] * (i - mid) - (sum[i] - sum[mid]) <= m) r = mid - 1;
				else l = mid + 1;
			}
			chkmax(ans, i - l);
		}
		cout << ans << '\n';
		
		return ;
	}
}
