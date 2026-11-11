#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 5e5 + 1, N = 501, T = M + N + 1;
ll c, n, m, d, q, w[M], k[N], xr, yr, dd[T];
vector <pair <ll, ll> > vct[T];
priority_queue <pair <ll, ll> > qq;
ll dj(ll x, ll y){
	while (!qq.empty()){
		qq.pop();
	}
	memset(dd, 0x7f, sizeof(dd));
	dd[x] = 0;
	qq.push({0, x});
	while (!qq.empty()){
		ll y = qq.top().second;
		if (qq.top().first > dd[y]){
			qq.pop();
			continue;
		}
		qq.pop();
		for (ll i = 0;i < vct[y].size();i++){
			ll t = vct[y][i].second;
			if (dd[y] + vct[y][i].first < dd[t]){
				dd[t] = dd[y] + vct[y][i].first;
				qq.push({dd[t], t});
			}
		}
	}
	return dd[y];
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (ll i = 1;i <= m;i++){
		cin >> w[i];
	}
	for (ll i = 1;i <= n;i++){
		cin >> k[i];
		for (ll j = 1;j <= k[i];j++){
			ll aij, tij;
			cin >> aij >> tij;
			vct[aij].push_back({tij, m + i});
			vct[m + i].push_back({tij, aij});
		}
	}
	for (ll i = 1;i <= q;i++){
		cin >> xr >> yr;
		ll ans = w[xr] + w[yr];
		ans += dj(xr, yr);
		cout << ans << "\n";
	}
	return 0;
}
