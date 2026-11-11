#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll c, t, n, d, x[222222], cf[5555], vis[5555], zy[5555], zcf, anss, cnt, ans;
ll dfs(ll id, ll mb, ll cx){
	vis[id] = cx;
	if (id == mb){
		if (cx == anss){
			cnt++;
		}
		if (cx < anss){
			anss = cx;
			cnt = 1;
		}
		return 0;
	}
	for (ll i = min(zy[id], mb) ; i > id ; i--){
		if (i == mb){
			dfs(i, mb, cx + 1);
			return 0;
		}
		if (vis[i] > cx + 1) dfs(i, mb, cx + 1);
	}
	return 0;
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--){
		cin >> n >> d >> x[0];
		for (ll i = 1 ; i < n ; i++){
			cin >> x[i];
			cf[i] = x[i] - x[i - 1];
		}
		zcf = 0;
		ans = 0;
		cf[0] = x[0];
		if (true){
			ll i = 0, j = 0;
			while (j < n){
				while (zcf > d){
					i++;
					zy[i] = j - 1;
					zcf -= cf[i];
				}
				zy[i] = j;
				j++;
				zcf += cf[j];
			}
			while (i < n){
				zy[i] = j - 1;
				i++;
			}
		}
		for (ll i = 0 ; i < n ; i++){
			for (ll j = i + 1 ; j < n ; j++){
				for (ll k = i ; k <= j ; k++){
					vis[k] = 1e18;
				}
				anss = 1e18;
				cnt = 0;
				dfs(i, j, 0);
				if (cnt == 2){
					ans++;
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
