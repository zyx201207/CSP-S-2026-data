#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5020;
int c, t, n, d, a[N], dis[N][N], ans;

signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t --){
		ans = 0;
		cin >> n >> d;
		for(int i = 1; i <= n; i++) cin >> a[i];
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				dis[i][j] = 1e18;
			}
			for(int j = i; j <= n; j++){
				if(a[j] - a[i] <= d) dis[i][j] = dis[j][i] = 1;
			}
			dis[i][i] = 0;
		}
		for(int i = n; i >= 1; i--){
			for(int j = i + 1, cnt; j <= n; j++){
				for(int k = i; k <= j; k++){
					if(a[k] - a[i] <= d) dis[i][j] = min(dis[i][j], dis[k][j] + 1);
				}
				cnt = 0;
				for(int k = i; k <= j; k++){
					if(a[k] - a[i] <= d && dis[i][j] == dis[k][j] + 1) cnt ++;
				}
//				cout << i << ' ' << j << ' ' << cnt << ' ' << dis[i][j] << endl;
				if(cnt == 2) ans ++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}