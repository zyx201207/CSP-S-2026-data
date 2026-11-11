#include<bits/stdc++.h>//24pts
typedef long long ll;
using namespace std;
const int maxn = 2e6 + 5, mod = 998244353;
const ll inf = 1e18;
ll n, d, a[maxn], ans, D[maxn];
void solve(){
	ans = 0;
	cin >> n >> d;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int U = 1; U <= n; U++){
		ll cnt = 1, last = a[U];
		for (int v = U + 1; v <= n; v++){
//			cout << "///" << U << " " << v << '\n';
			for (int i = 1; i <= n; i++) D[i] = inf;
			queue<pair<ll, ll>>q;
			q.push({U, 0});
			D[U] = 0;
			while (!q.empty()){
				ll u = q.front().first, dis = q.front().second;
				q.pop();
				if (u == v){
					ll cnt = 0;
//					cout << "----------------------------\n";
					while (!q.empty() && q.front().second == dis){
//						cout << q.front().first << " " << dis << '\n';
						if (q.front().first == v) cnt++;
						q.pop();
					}
//					cout << "****************************\n";
					if (cnt == 1) ans++;
					break;
				}
				for (ll i = u + 1; i <= n; i++){
					if (a[i] - a[u] > d) break;
					if (D[i] < dis + 1) continue;
					D[i] = dis + 1;
					q.push({i, dis + 1});
				}
			}
		}
	}
	cout << ans << '\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int C, T;
	cin >> C >> T;
	while (T--) solve();
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5


0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/