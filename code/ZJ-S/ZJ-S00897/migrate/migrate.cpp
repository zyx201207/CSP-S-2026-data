#include <bits/stdc++.h>
using namespace std;
using ll = long long; using ull = unsigned long long;

constexpr int MAXN = 5000 + 10;
ll a[MAXN], step[MAXN][MAXN];

void solve() {
	ll n, d;
	cin >> n >> d;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++) {
		step[i][i] = 0;
		for(int j = i + 1; j <= n; j++)
			step[i][j] = 0x3f3f3f3f;
	}
	for(int k = 1; k <= n; k++) {
		for(int i = k; i <= n; i++) {
			for(int j = i; j <= n; j++) {
				if(a[j] - a[i] <= d)
					step[k][j] = min(step[k][j], step[k][i] + 1);
			}
		}	
	}
	/*for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++)
			cout << step[i][j] << " ";
		cout << "\n"; 
	}*/
	
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++) {
			ll cnt = 0;
			for(int k = i + 1; k <= j - 1; k++) {
				if(step[i][k] + step[k][j] == step[i][j]) cnt++;
			}
			if(cnt == 2) ans++;
		}
	}
	cout << ans << "\n";
}

int main() {
	freopen("migrate.in", "r", stdin), freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int c, T;
	cin >> c >> T;
	
	while(T--) solve();
	return 0;
}

