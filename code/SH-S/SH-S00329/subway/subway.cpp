#include <bits/stdc++.h>
using namespace std; 

#define int long long 
int id, n, m, d, q; 
// id -> 测试点编号
// n -> 地铁线路数
// m -> 地铁站数
// d -> 每个地铁站最多被几条线路经过
// q -> 询问数 
int w[1000]; // 地铁口到地铁厅 
void solve1() {
	int edge[1000][1000], dis[1000][1000]; 
	vector <int> G[1000]; 
	memset(edge, 0x3f, sizeof(edge)); 
	for (int i = 1; i <= n; i ++) { // n条线路 
		int k; cin >> k; // 经过点数
		for (int j = 1; j <= k; j ++) {
			int p, w; cin >> p >> w; 
			edge[p][m+i] = edge[m+i][p] = w; 
			G[p].push_back(m+i); // 从p能走到m+i号站台 
		} 
		// 输入线路 厅和台之间的边 
	}
	memset(dis, 0x3f, sizeof(dis)); 
	// m 个厅和n个台 
	for (int i = 1; i <= m + n; i ++) {
		edge[i][i] = 0; 
	}
	for (int i = 1; i <= m + n; i ++) {
		for (int j = 1; j <= m + n; j ++) {
			dis[i][j] = edge[i][j];
		}
	}
	for (int k = 1; k <= m + n; k ++) {
		for (int i = 1; i <= m + n; i ++) {
			for (int j = 1; j <= m + n; j ++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]); 
			}
		}
	}
	while (q --) {
		int s, t; cin >> s >> t; 
		int ans = 0x3fffffff; 
		ans = w[s] + w[t] + dis[s][t]; 
		cout << ans << endl; 
	}

}
struct Node_2 {int v, w; };
void solve2() { // id = 7, 8(A)
	int edge[1005][1005], dis[1005][1005]; 
	vector <int> G[1005]; 
	memset(edge, 0x3f, sizeof(edge)); 
	for (int i = 1; i <= n; i ++) { // n条线路 
		int k; cin >> k; // 经过点数
		if (k == 1) {int ar, br; cin >> ar >> br; continue; }
		int ap, aw, bp, bw; 
		cin >> ap >> aw >> bp >> bw; // k == 2
		edge[ap][bp] = edge[bp][ap] = min(edge[ap][bp], aw + bw); 
		// 输入线路 厅和厅之间的边 
	}
	for (int i = 1; i <= m; i ++) {
		edge[i][i] = 0; 
	}
	for (int i = 1; i <= m; i ++) {
		for (int j = 1; j <= m; j ++) {
			dis[i][j] = edge[i][j];
		}
	}
	for (int k = 1; k <= m; k ++) {
		for (int i = 1; i <= m; i ++) {
			for (int j = 1; j <= m; j ++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]); 
			}
		}
	}
	while (q --) {
		int s, t; cin >> s >> t; 
		int ans = 0x3fffffff; 
		ans = w[s] + w[t] + dis[s][t]; 
		cout << ans << endl; 
	}
}
signed main() { // O((n+m)^3)
	freopen("subway.in", "r", stdin); 
	freopen("subway.out", "w", stdout); 
	cin >> id >> n >> m >> d >> q;   
	for (int i = 1; i <= m; i ++) {
		cin >> w[i]; 
		// 台 -> 厅 
	}
	if (1 <= id && id <= 6) {
		solve1(); 
		return 0; 
	}
	if (7 <= id && id <= 8) {
		solve2(); 
		return 0; 
	}
	solve1(); 
}

