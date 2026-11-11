#include <bits/stdc++.h>
using namespace std;
#define int long long
pair<int, int> edge[500005][22];
int du[500005], dis[505][505];
int C, n, m, d, q, a[500005];
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> C >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> a[i];
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++){
			int x, len;
			cin >> x >> len;
			edge[x][++du[x]] = {i, len};
		}
	}
	
	memset(dis, 0x3f, sizeof(dis));
	for(int i = 1; i <= n; i++) dis[i][i] = 0;
	
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= du[i]; j++){
			for(int k = j + 1; k <= du[i]; k++){
				int len = edge[i][j].second + edge[i][k].second;
				int x = edge[i][j].first, y = edge[i][k].first;
				
				dis[x][y] = min(dis[x][y], len);
				dis[y][x] = min(dis[y][x], len);
			}
		}
	}
	
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	
	while(q--){
		int x, y;
		cin >> x >> y;
		
		int ans = (int)1e18;
		for(int i = 1; i <= du[x]; i++){
			for(int j = 1; j <= du[y]; j++){
				int S = edge[x][i].first, T = edge[y][j].first;
				ans = min(ans, dis[S][T] + edge[x][i].second + edge[y][j].second + a[x] + a[y]);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
