#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 505, M = 5e5 + 5;
int c, n, m, d, q;
vector<pair<int, int>> swid[M];
int w[M];
int dis[N][N];
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
//	freopen("subway\\subway7.in", "r", stdin);
//	freopen("subway\\subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++) cin >> w[i];
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++) dis[i][j] = 0x3f3f3f3f3f3f3f3f;
	for (int i = 1; i <= n; i ++) dis[i][i] = 0;
	for (int i = 1, k; i <= n; i ++){
		cin >> k;
		for (int a, t; k --; ){
			cin >> a >> t;
			for (const auto& lst : swid[a]){
				int p = lst.first, w = lst.second;
				dis[p][i] = min(dis[p][i], w + t);
				dis[i][p] = min(dis[i][p], w + t);
			}
			swid[a].push_back({i, t});
		}
	}
	for (int k = 1; k <= n; k ++)
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	for (int x, y; q --; ){
		cin >> x >> y;
		int ans = LLONG_MAX;
		for (const auto& A : swid[x])
			for (const auto& B : swid[y])
				ans = min(ans, w[x] + w[y] + A.second + B.second + dis[A.first][B.first]);
		cout << ans << "\n";
	}
}