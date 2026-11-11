#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e6 + 10;
ll x[N];
int T, n;
int c, cnt;
ll d, ans;
inline ll lower(int l, int r, ll k) {
	int L = l, R = r;
	int Mid = 0;
	ll res = -2e18;
	while(L <= R) {
		Mid = (L + R) >> 1;
		if(x[Mid] <= k) {
			L = Mid + 1;
			res = max(res, x[Mid]);
		}
		else
			R = Mid - 1;
	}
	return res;
}
void dfs(int v, int w, int now, int ma) {
	if(x[v] + 1ll*(ma - now) * d < x[w]) return ;
	if(cnt > 2) return ;
	if(v == w) {
		if(now == ma)
			++cnt;
		return ;
	}
	for(int i = v + 1; i <= n; ++i)
		if(x[i] - x[v] <= d)
			dfs(i, w, now + 1, ma);
		else
			break;
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> T;
	while(T--) {
		cin >> n >> d;
		ans = 0;
		for(int i = 1; i <= n; ++i)
			cin >> x[i];
		for(int i = 1; i <= n; ++i)
			for(int j = i + 3; j <= n; ++j) {
				if(x[j] - x[i] <= d) continue;
				ll r = x[i];
				int tot = 0;
				cnt = 0;
				while(r <= x[j]) {
					r = lower(i, n, r) + d;
					++tot;
				}
				dfs(i, j, 0, tot);
				if(cnt == 2) ++ans;
			}
		cout << ans << '\n';
	}
	return 0;
}
