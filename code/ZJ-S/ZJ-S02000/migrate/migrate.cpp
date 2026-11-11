#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 2e6 + 10;
template<typename T>
void debug(const T &x) { cout << x << '\n'; }
template<typename Type, typename ...Types>
void debug(const Type &arg, const Types &...args) { cout << arg << ' '; debug(args...); }
#ifdef LOCAL
#define dbg(...) cout << "[" << #__VA_ARGS__ << "]: ", debug(__VA_ARGS__)
#else
#define dbg(...) 42
#endif

namespace Loop1st {
int n, r[N], f[5010][5010];
ll s1[N], s2[N];
ll d, a[N];
void init() {

}
void Main() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) cin >> a[i], s1[i] = s2[i] = 0;
	for (int u = 1; u <= n; u++) {
		r[u] = upper_bound(a + 1, a + n + 1, a[u] + d) - a - 1;
		// dbg(r[u]);
	}
	r[0] = 1;
	for (int u = n; u; u--) if (r[u] > u) {
		int typ = (r[u] != r[u - 1] ? 0 : (u > 2 && r[u] == r[u - 2] ? 2 : 1));
		if (typ == 2) s1[u] = s2[u] = 0;
		else if (typ == 1) {
			s1[u] = 0;
			s2[u] = s1[r[u]];
			if (u > 2) s2[u] += r[u - 2] >= u && r[u - 1] != u - 1 ? r[u - 1] - r[u - 2] : 0;
			 // + (u > 2 ? r[u - 1] - r[u - 2] : r[u - 1] - 1);
		} else {
			s1[u] = s1[r[u]] + r[u] - r[u - 1];
			s2[u] = s2[r[u]];
			if (u > 2) s2[u] += r[u - 2] >= u && r[u - 1] != u - 1 ? r[u - 1] - r[u - 2] : 0;
			// + (u > 2 ? r[u - 1] - r[u - 2] : r[u - 1] - 1);
		}
		// assert(r[u] == u + 2);
		// dbg(u, r[u], typ, s1[u], s2[u], s2[r[u]]);
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += s2[r[i]];
	}
	cout << ans << '\n';
}

}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	auto st = clock();
	int C = 0, T = 1;
	cin >> C >> T;
	while (T--) Loop1st::Main();
	cerr << fixed << setprecision(10) << "Time = " << 1. * (clock() - st) / CLOCKS_PER_SEC << '\n';
	return 0;
}
