#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define open(_io) freopen(_io".in", "r", stdin), freopen(_io".out", "w", stdout)
#define io ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const ll _n = 2e6 + 1, _inf = LLONG_MAX;
ll c, t, n, d, s, x[_n], l[_n], y[_n];
void work(){
	cin >> n >> d, s = 0;
	for (ll i = 1; i <= n; ++i) cin >> x[i];
	for (ll k = 1; k <= n - 3; ++k){
		l[k] = 0, y[k] = 1;
		for (ll i = k + 1; i <= n; ++i) l[i] = y[i] = 0;
		for (ll i = k + 1; i <= n; ++i){
			ll p = lower_bound(x + k, x + n + 1, x[i] - d) - x;
			l[i] = _inf;
			for (ll j = p; j < i; ++j) l[i] = min(l[i], l[j]);
			if (l[i] == _inf) break;
			for (ll j = p; j < i; ++j) if (l[j] == l[i]) y[i] += y[j];
			++l[i];
			if (y[i] == 2) ++s;
		}
	}cout << s << '\n';
}
int main(){
	open("migrate");
	io;
	cin >> c >> t;
	while (t--) work();
	return 0;
}

