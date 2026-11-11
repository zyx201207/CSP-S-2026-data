#include <vector>
#include <queue>
#include <bits/stdc++.h>
#define ll long long
#define int ll
#define fi first
#define se second
#define pii pair<ll , ll>
#define mk make_pair
using namespace std;
const int N = 2e6 + 10 , M = 5e2 + 10;
ll id , T , n , d , a[N] , re[N] , f[N] , g[N][4] , h[N] , sumh[N];
signed main(){
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> id >> T;
	while (T --){
		cin >> n >> d;
		for (int i = 1;i <= n;i ++) cin >> a[i];
		if (n == 1){
			cout << "0\n";
			continue;
		}
		if (id == 11 || id == 12){
			ll x = a[2] - a[1] , r = d / x;
			r = r * 2 - 1;
			if (r <= 1) cout << 0 << "\n";
			else cout << max(0ll , n - r) << "\n";
			continue;
		}
		for (int i = 1;i <= n;i ++) re[i] = f[i] = g[i][1] = g[i][2] = g[i][3] = h[i] = sumh[i] = 0;
		for (int i = 1;i <= n;i ++){
			ll l = i , r = n , mid;
			while (l <= r){
				mid = (l + r) / 2;
				if (a[mid] - a[i] <= d) l = mid + 1 , re[i] = mid;
				else r = mid - 1;
			}
		}
		for (int i = 1;i <= n;i ++){
			h[i] = h[re[i]] + re[i] - re[i - 1] + 1;
		}
		ll ans = 0;
		for (int i = n;i >= 1;i --){
			ll x = re[i];
			if (x == i) f[i] = 0;
			else if (x == i + 1) f[i] = f[i + 1];
			else if (x == i + 2){
				ll u = re[x] , v = re[x - 1];
				f[i] = v - x;
			}
			else{
				ll u = re[x];
				f[i] = g[u][3];
			}
			g[i][1] = f[i];
			if (i != 1 && re[i] == re[i - 1]) g[i][2] = h[re[i]];
			else if (i != 1 && re[i] != re[i - 1]) g[i][2] = g[re[i]][min(3ll , re[i] - re[i - 1])];
			if (i >= 3){
				ll u = re[i] , v = re[i - 1] , w = re[i - 2];
				if (u == v && v == w) g[i][3] = 0;
				else if (u == v && v > w) g[i][3] = u - w - 1 + h[u];
				else if (u > v && v == w) g[i][3] = g[u][min(3ll , u - v)];
				else g[i][3] = g[u][min(3ll , u - v)] + v - w;
			}
			ans += f[i];
		}
		cout << ans << "\n";
	}
	return 0;
}
/*
11 1
5 2
1 2 3 4 5
*/