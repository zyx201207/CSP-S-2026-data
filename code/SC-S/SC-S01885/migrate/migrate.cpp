#include <bits/stdc++.h>
#define int long long
using namespace std;
int c, t;
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c;
	cin >> t;
	while(t--){
		int n, d, g[1005][1005], cnt[1005][1005], ans;
		cin >> n >> d;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				cnt[i][j] = 1;
				if(i == j){
					g[i][j] = 0;
				}else{
					g[i][j] = 10000000005;
				}
			}
		}
		for(int i = 1; i <= n; i++){
			int x;
			cin >> x;
			if(x > d){
				continue;
			}
			g[i][i - 1] = x;
			g[i - 1][i] = x;
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				for(int k = 1; k <= n; k++){
					if(g[i][k] + g[k][j] == g[i][j]){
						cnt[i][j]++;
					}else{
						cnt[i][j] = 1;
						g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
					}
				}
			}
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				ans = max(ans, cnt[i][j]);
			}
		}
		cout << ans << endl;
	}
	return 0;
}