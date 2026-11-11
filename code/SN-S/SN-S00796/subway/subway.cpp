#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
using pii = pair<int, ll>;
const int N = 5e2 + 5, M = 5e5 + 5;
const ll INF = 1e18;
int c, n, m, d, q;
ll w[M], f[N][N];
vector<pii> p[M];
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++){
			int a;
			int t;
			cin >> a >> t;
			p[a].push_back({i, t});
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i != j) f[i][j] = INF;
		}
	}
	for(int i = 1; i <= m; i++){
			//cout << i << "\n";
		for(int j1 = 0; j1 < p[i].size(); j1++){
			//cout << p[i][j1].first << " ";
			for(int j2 = j1 + 1; j2 < p[i].size(); j2++){
				int k1 = p[i][j1].first, k2 = p[i][j2].first;
				ll t1 = p[i][j1].second, t2 = p[i][j2].second;
				f[k1][k2] = min(f[k1][k2], t1 + t2);
				f[k2][k1] = min(f[k2][k1], t1 + t2);
			}
		}
		//cout << "\n";
	}
//	for(int i = 1; i <= n; i++){
//		for(int j = 1; j <= n; j++){
//			if(f[i][j] != INF && i != j) cout << i << " " << j << " " << f[i][j] << "\n";
//		}
//	}
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	while(q--){
		int x, y;
		cin >> x >> y;
		int ans = INF;
		for(int i = 0; i < p[x].size(); i++){
			for(int j = 0; j < p[y].size(); j++){
				ans = min(ans, f[p[x][i].first][p[y][j].first] + p[x][i].second + p[y][j].second);
			}
		}
		ans += w[x] + w[y];
		cout << ans << "\n";
	}
	return 0;
}
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2

