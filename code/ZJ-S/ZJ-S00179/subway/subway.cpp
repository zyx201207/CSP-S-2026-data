#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define open(_io) freopen(_io".in", "r", stdin), freopen(_io".out", "w", stdout)
#define io ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const ll _m = 5e5 + 1, _n = 500 + 2, _d = 20 + 1, _inf = LLONG_MAX;
ll c, n, m, d, q, k, a, x, y, id = 0, w[_m], p[_n], s[_m][_d], t[_m], where[_m];
ll which(const ll& node){
	return upper_bound(p + 1, p + n + 1, node) - p;
}
ll nodeonline(const ll& sta, const ll& line){
	for (ll i = 1; i <= s[sta][0]; ++i){
		ll wh = which(s[sta][i]);
		if (wh == line) return s[sta][i];
		if (wh > line) return -1;
	}return -1;
}
ll dfs(const ll& fa, const ll& Fa, const ll& e, const ll& ans){
	ll wh = which(fa), wr = where[fa], node = nodeonline(e, wh);
	if (node != -1) return ans + t[node];
	ll minv = _inf;
	for (ll i = p[wh]; i < p[wh + 1]; ++i) if (i != fa && i != Fa) minv = min(minv, dfs(i, fa, e, ans + t[i]));
	for (ll i = 1; i <= s[wr][0]; ++i) if (i != fa && i != Fa) minv = min(minv, dfs(i, fa, e, ans + t[i]));
	return ans + minv;
}
int main(){
	open("subway");
	io;
	cin >> c >> n >> m >> d >> q;
	for (ll i = 1; i <= m; ++i) cin >> w[i];
	for (ll i = 1; i <= n; ++i){
		cin >> k, p[i] = id;
		for (ll j = 1; j <= k; ++j) cin >> a >> x, where[t[s[a][++s[a][0]] = ++id] = x] = a;
	}p[n + 1] = id;
	while (q--){
		cin >> x >> y;
		ll ans = _inf;
		for (ll i = 1; i <= s[x][0]; ++i) ans = min(ans, dfs(s[x][i], -1, y, t[s[x][i]]));
		cout << w[x] + w[y] + ans << '\n';
	}return 0;
}

