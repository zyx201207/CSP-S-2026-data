/*
咦！最短路题，我康康
n 只有 500，好想 Floyd
让我思考一下
如果有从第 i 条线路到第 j 条线路的最短路 
那么只需要枚举 d^2 种配对就可以回答询问（记得加上出入站和初始走到站台）
然后我们神奇地发现，对于每个地铁站我们去枚举 d^2/2 种配对，然后暴力建图是 O(d^2/2 m) 可以接受的
然后直接 Floyd！！！
是这样吗题没读假吧 
多测不清空 1=->0= （妈呀 c 是测试点编号不是测试数据组数） 
CCF T2 放绿还是太良心了，不像去年 NOIP 
不要用 endl!!! 
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 502, M = 5e5 + 5, Q = 1e5 + 5;
constexpr long long INF = 4e18;
vector<pair<int, int> > trains[M];
int dist[N][N];
int w[M];
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout); 
	cin.tie(0);
	ios::sync_with_stdio(false);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i) cin >> w[i];
	for (int i = 1; i <= n; ++i) {
		int ki;
		cin >> ki;
		for (int j = 1; j <= ki; ++j) {
			int stp, tm;
			cin >> stp >> tm;
			trains[stp].emplace_back(i, tm);
		}
	}
	
	// 遍历车站 
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) dist[i][j] = (i == j) ? 0 : INF;
	for (int i = 1; i <= m; ++i) {
		for (int j = 0; j < trains[i].size(); ++j) {
			for (int k = j + 1; k < trains[i].size(); ++k) {
				dist[trains[i][j].first][trains[i][k].first] = min(
						dist[trains[i][j].first][trains[i][k].first],
						trains[i][j].second + trains[i][k].second
					);
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; ++j) {
			dist[i][j] = dist[j][i] = min(dist[i][j], dist[j][i]);
		}
	}
	// Floyd
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int k = 1; k <= n; ++k) {
				dist[i][j] = min(dist[i][k] + dist[j][k], dist[i][j]);
			}
		}
	}
	
	for (int i = 1; i <= q; ++i) {
		int xr, yr;
		cin >> xr >> yr;
		
		int ans = INF;
		for (auto t1 : trains[xr]) {
			for (auto t2 : trains[yr]) {
				ans = min(ans, t1.second + t2.second + dist[t1.first][t2.first]);
			}
		}
		cout << ans + w[xr] + w[yr] << '\n';
	}
	return 0;
} 
