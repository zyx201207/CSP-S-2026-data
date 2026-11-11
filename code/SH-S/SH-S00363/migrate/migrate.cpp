#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 5e3 + 10;
int C, T, n, d, a[maxn], f[maxn][maxn], g[maxn][maxn];

void solve(){
	cin >> n >> d;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	int ans = 0;
	for (int i = 1; i <= n; i++){
		g[i][i] = 0;
		for (int j = i + 1; j <= n; j++){
			int mind = LONG_LONG_MAX;
			f[i][j] = 0;
			for (int k = j - 1; k >= i; k--){
				if (a[j] - a[k] <= d){
					g[i][j] = g[i][k] + 1;
					mind = min(mind, g[i][j]);
				}
			}
			
			for (int k = j - 1; k >= i; k--){
				if (a[j] - a[k] <= d && mind == g[i][k] + 1){
					if (a[k] - a[i] <= d) f[i][k] = 1;
					f[i][j] += f[i][k];
					//if (i == 1 && j == 3) cout << k << ' ';
				}
 			}
			
			//cout << endl;
			if (f[i][j] == 2) ans++;
			//cout << i << ' ' << j << ' ' << f[i][j] << endl;
		}
	}
	
	cout << ans << endl;
	return;
}

signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> C >> T;
	while (T--) solve();
	return 0;
}
