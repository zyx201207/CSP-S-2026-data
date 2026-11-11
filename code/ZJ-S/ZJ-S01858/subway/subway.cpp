#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3e4 + 10, M = 1600;
int c, n, m, d, q;
int a[N], f[M][M];
void solve1(){
	for (int i = 1; i <= n + m; i ++){
		for (int j = 1; j <= n + m; j ++){
			f[i][j] = 1000000000000000ll;
		}
		f[i][i] = 0;
	}
	int k, x, y;
	for (int i = 1; i <= n; i ++){
		cin >> k;
		for (int j = 1; j <= k; j ++){
			cin >> x >> y;
			f[m + i][x] = min(f[m + i][x], y);
			f[x][m + i] = min(f[x][m + i], y);
		}
	}
	
	for (int k = 1; k <= n + m; k ++){
		for (int i = 1; i <= n + m; i ++){
			for (int j = 1; j <= n + m; j ++){
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	for (int i = 1; i <= q; i ++){
		cin >> x >> y;
		int ans = a[x] + a[y] + f[x][y];
		cout << ans << '\n';
	}
}
vector <int> e[N];
int w;
int pth[510][N];
queue<int> qq;
void bfs(int x){
	for (int i = 1; i <= m + n; i ++) pth[x][i] = -1;
	pth[x][m + x] = 0;
	while (!qq.empty()) qq.pop();
	qq.push(x + m);
	while (!qq.empty()){
		int u = qq.front();
		qq.pop();
		for (int v : e[u]){
			if (pth[x][v] != -1) continue;
			pth[x][v] = pth[x][u] + 1;
			qq.push(v);
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++){
		cin >> a[i];
	}
	if (c <= 11) {
		solve1();
		return 0;
	}
	int k, x, y;
	for (int i = 1; i <= n; i ++){
		cin >> k;
		for (int j = 1; j <= k; j ++){
			cin >> x >> y;
			w = y;
			e[x].push_back(m + i);
			e[m + i].push_back(x);
		}
	}
	for (int i = 1; i <= n; i ++){
		bfs(i);
	}
	for (int i = 1; i <= q; i ++){
		cin >> x >> y;
		int ans = 1000000000000000ll;
		for (int j = 1; j <= n; j ++){
			ans = min(ans, pth[j][x] + pth[j][y]);
		}
		ans *= w;
		ans += a[x] + a[y];
		cout << ans << '\n';
	}
	return 0;
}
