#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5010;
int n, ans;
ll x[N], d;
int dis[N][N];
int g[N][N];
void solve(){
	ans = 0;
	cin >> n >> d;
	for (int i = 1; i <= n; i ++){
		cin >> x[i];
	}
	for (int i = 1; i <= n; i ++){
		dis[i][i] = 0;
		int cur = i, tmp = 0, lst = i;
		for (int j = i + 1; j <= n; j ++){
			if (x[j] - x[lst] <= d){
				dis[i][j] = tmp + 1;
			}
			else if (x[j] - x[j - 1] > d){
				break;
			}
			else{
				tmp ++;
				dis[i][j] = tmp + 1;
				lst = j - 1;
			}
		}
	}
	for (int i = n - 1; i >= 1; i --){
		for (int j = i + 1; j <= n; j ++){
			if (x[j] - x[j - 1] > d) break;
			if (x[j] - x[i] <= d){
				g[i][j] = 1;
				continue;
			}
			int sum = 0;
			for (int k = i + 1; k < j; k ++){
				if (x[k] - x[i] <= d && dis[k][j] + 1 == dis[i][j]){
					sum += g[k][j];
					if (sum >= 3) break;
				}
			}
			g[i][j] = sum;
			if (sum == 2) ans ++;
		}
	}
	cout << ans << '\n';
	for (int i = 1; i <= n; i ++){
		for (int j = 1; j <= n; j ++){
			dis[i][j] = -1;
			g[i][j] = 0;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, T;
	cin >> c >> T;
	memset(dis, -1, sizeof(dis));
	memset(g, 0, sizeof(g));
	while (T --){
		if (0 <= c && c <= 25) solve();
	}
	return 0;
}
