#include<bits/stdc++.h>

using namespace std;

using ll = long long;
const int N = 505;
const int M = 5e5 + 5;
const int D = 25;
const ll inf = 1e16;
int w[M];
ll g[N][N];
map<int, int> t[M];
vector<int> a[M];

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int c, m, n, d, q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++){
			int v;
			ll cost;
			cin >> v;
			a[v].push_back(i);
			cin >> cost;
			t[v][i] = cost;
		}
		for(int j = 1; j <= n; j++)g[i][j] = inf;
	}
	for(int k = 1; k <= m; k++){
		int len = a[k].size() - 1;
		for(int i = 0; i <= len; i++){
			for(int j = i + 1; j <= len; j++){
				int &u = a[k][i], &v = a[k][j];
				g[u][v] = g[v][u] = min(g[u][v], ll(t[k][u] + t[k][v]));
			}
		}
	}
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				if(i != j && j != k && i != k){
					g[i][j] = g[j][i] = min(g[i][j], g[i][k] + g[k][j]);
				}
				if(i == j)g[i][j] = 0;
			}
		}
	}
	while(q--){
		int x, y;
		ll ans = inf;
		cin >> x >> y;
		for(int i = 0; i < a[x].size(); i++){
			for(int j = 0; j < a[y].size(); j++){
				ans = min(ans, g[a[x][i]][a[y][j]] + t[x][a[x][i]] + t[y][a[y][j]]);
			}
		}
		cout << ans + w[x] + w[y] << '\n';
	}
	return 0;
} 
