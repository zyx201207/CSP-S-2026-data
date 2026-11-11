#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2e6 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
int f[MAXN], n, c;
ll x[MAXN], g[MAXN], sum[MAXN], d;
void solve_sub123(){
	ll ans = 0;
	for (int i = 1; i <= n; i++){
		f[i] = 0;
		g[i] = 1;
		for (int j = 1; j <= n; j++){
			sum[j] = 0;
		}
		sum[0] = 1;
		queue <int> q;
		q.push(i);
		for (int j = i + 1; j <= n; j++){
			while (!q.empty() && x[j] - x[q.front()] > d){
				int k = q.front();
				if (f[k] <= n){
					sum[f[k]] = (sum[f[k]] - g[k] + MOD) % MOD;
				}
				q.pop();
			}
			if (!q.empty()){
				f[j] = f[q.front()] + 1;
				if (f[j] <= n){
					g[j] = sum[f[j] - 1];
				}
			}
			else{
				f[j] = INF;
			}
			q.push(j);
			if (f[j] <= n){
				sum[f[j]] = (sum[f[j]] + g[j]) % MOD;
			}
			if (g[j] == 2){
				ans++;
			}
		}
	}
	cout << ans << "\n";
	return;
}
void solve_sub4(){
	ll dx = x[2] - x[1], ans = 0;
	if (d / dx <= 1){
		cout << 0 << "\n";
		return;
	}
	for (int i = 1; i <= n; i++){
		if (i + 2 * (d / dx) - 1 <= n){
			ans++;
		}
	}
	cout << ans << "\n";
	return;
}
void solve(){
	cin >> n >> d;
	for (int i = 1; i <= n; i++){
		cin >> x[i];
	}
	if (c <= 10){
		solve_sub123();
	}
	else if (c <= 12){
		solve_sub4();
	}
	else{
		cout << 0 << "\n";
	}
	return;
}
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> c >> t;
	while (t--){
		solve();
	}
	return 0;
}