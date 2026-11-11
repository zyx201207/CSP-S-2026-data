#include <bits/stdc++.h>
#define eb emplace_back
#define int long long
using namespace std;
const int N = 510, M = 6e5 + 10, inf = 1e17; 
int c, n, m, d, q;
struct Node{
	int to;
	int val;
};
vector<Node> e[M]; // 表示地铁口和路线之间的边 
int dis[N][N], siz[N], w[M]; // siz[i] 表示第 i 个路线相连的地铁站的个数 
// 路线的编号是 [m+1,m+n] 
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin.tie(0);
	std::ios::sync_with_stdio(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++){
		cin >> siz[i];
		for(int j = 1; j <= siz[i]; j++){
			int v, w;
			cin >> v >> w;
			e[i + m].eb(Node{v, w});
			e[v].eb(Node{i + m, w});
		}
	}
	memset(dis, 0x3f, sizeof dis);
	for(int i = 1; i <= n; i++) dis[i][i] = 0;
	for(int i = 1; i <= m; i++){
		for(auto u : e[i]){
			for(auto v : e[i]){
				dis[u.to - m][v.to - m] = min(dis[u.to - m][v.to - m], u.val + v.val);
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
	for(int i = 1; i <= q; i++){
		int x, y;
		cin >> x >> y;
		int ans = inf;
		for(auto u : e[x]){
			for(auto v : e[y]){
				ans = min(ans, dis[u.to - m][v.to - m] + v.val + u.val);
			}
		}
		cout << ans + w[x] + w[y] << "\n";
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
