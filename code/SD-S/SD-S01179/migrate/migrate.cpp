#include <bits/stdc++.h>

#define debug(...) fprintf(stderr, __VA_ARGS__)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;

constexpr int MaxN = 2e6 + 10;
constexpr int inf = 20;

int n;
ll D, X[MaxN];

int pre[MaxN], nxt[MaxN];
int f[MaxN], g[MaxN], pos[MaxN];

void solve() {
	cin >> n >> D;
	for (int i = 1; i <= n; i++)
		cin >> X[i];
		
	bool sub = true;
	ll det = X[2] - X[1];
	for (int i = 2; i <= n; i++)
		sub &= X[i] - X[i - 1] == det;
		
	if (sub == true) {
//		debug(" D = %lld, det = %lld\n", D, det);
		if (D < det * 2) {
			cout << "0\n";
			return;
		}
		ll crs = D / det;
		crs = 2 * crs - 1;
		cout << max(0ll, n - crs) << '\n';
		return;
	}
	
	if (n > 5000) {
		cout << "0\n";
		return;
	}
		
	for (int i = 1; i <= n; i++) {
		int x = i;
		while (x && X[i] - X[x] <= D) -- x;
		pre[i] = x;
//		debug(" pre[%d] = %d\n", i, x);
	}
	
	ll ans = 0;
	for (int l = 1; l <= n; l++) {
		for (int i = 0; i <= n; i++)
			f[i] = g[i] = pos[i] = 0;
		f[l] = 1;
		pos[0] = l;
		for (int r = l + 1; r <= n; r++) {
			g[r] = g[pre[r] + 1] + 1;
			f[r] = f[pos[g[r] - 1]] - f[pre[r]];
			pos[g[r]] = r; 
//			debug(" [%d, %d] -> (%d, %d - [%d]%d)\n", l, r, f[r], g[r], pre[r] + 1, g[pre[r] + 1]);
			if (f[r] == 2) {
				++ ans;
//				debug("(%d, %d)\n", l, r);
			}
			f[r] += f[r - 1];
		}
	}
	
	cout << ans << '\n';
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int cid, T;
	T = 1;
	cin >> cid >> T;
	while (T--) solve(); 
}

/*
0 2
5 10000
-2 -1 0 1 2
6 10000
-4 -3 -2 -1 3 6

*/
/*
#include <bits/stdc++.h>

#define debug(...) fprintf(stderr, __VA_ARGS__)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;

constexpr int MaxN = 2e6 + 10;
constexpr int inf = 20;

int n;
ll D, X[MaxN];

int pre[MaxN], nxt[MaxN];
vector<int> vpre[MaxN], vnxt[MaxN];
ll wpre[MaxN], wnxt[MaxN];

void solve() {
//	debug("-----------------------\n");
	cin >> n >> D;
	for (int i = 1; i <= n; i++)
		cin >> X[i];
	
	for (int i = 0; i <= n + 1; i++)
		vpre[i].clear(), vnxt[i].clear();
	
	X[0] = -4e18;
	X[n + 1] = 4e18;
	
	for (int i = 1; i <= n; i++)
		wpre[i] = wnxt[i] = 1;
	
	for (int i = 1, j = 0; i <= n; i++) {
		while (j <= i && X[i] - X[j] > D) ++ j;
		pre[i] = j;
		if (j < i - 1) vpre[j].emplace_back(i);
	}
	for (int i = n, j = n + 1; i >= 1; --i) {
		while (j >= i && X[j] - X[i] > D) -- j;
		nxt[i] = j;
		if (j > i + 1) vnxt[j].emplace_back(i);
	} 
	for (int i = 1; i <= n; i++)
		if (nxt[i] > i) wnxt[nxt[i]] += wnxt[i];
	for (int i = n; i >= 1; --i)
		if (pre[i] < i) wpre[pre[i]] += wpre[i];
	
	debug("nxt[] = ");
	for (int i = 1; i <= n; i++)
		debug("%d ", nxt[i]);
	debug("\n"); 
	debug("pre[] = ");
	for (int i = 1; i <= n; i++)
		debug("%d ", pre[i]);
	debug("\n");
	debug("wnxt[] = ");
	for (int i = 1; i <= n; i++)
		debug("%lld ", wnxt[i]);
	debug("\n");
	debug("wpre[] = ");
	for (int i = 1; i <= n; i++)
		debug("%lld ", wpre[i]);
	debug("\n");
	
	ll ans = 0;
	for (int i = 1; i < n; i++) {
		if (vpre[i].size() * vnxt[i + 1].size() == 0) continue;
		debug(" vpre[%d] = ", i);
		for (auto x : vpre[i]) debug("%d ", x);
		debug("\n");
		debug("vnxt[%d] = ", i + 1);
		for (auto x : vnxt[i + 1]) debug("%d ", x);
		debug("\n");
		int x = vpre[i].back();
		int y = vnxt[i + 1].back();
		ll wp = 0, wn = 0;
		debug(" nxt[%d] = %d, pre[%d] = %d\n", i + 1, nxt[i + 1], i, pre[i]);
		if (nxt[i + 1] > x && pre[i] < y) {
		   wp = vpre[i].size(), wn = vnxt[i + 1].size();
		} else {
		  wp = vpre[i].size() - 1 + wpre[x];
		   wn = vnxt[i + 1].size() - 1 + wnxt[y];
		}
		x = vpre[i][0], y = vnxt[i + 1][0];
		debug(" (%d, %d) -> %lld * %lld\n", x, y, wpre[x], wnxt[y]);
		ans += wp * wn;
    }
	cout << ans << '\n';
}

signed main() {
	freopen("migrate3.in", "r", stdin);
//	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int cid, T;
	cin >> cid >> T;
	while (T--) solve(); 
}

*/

/*
坐落于大都市顶点空想构筑的理想乡
将这一切湮灭的将是谁的愿望
*/

