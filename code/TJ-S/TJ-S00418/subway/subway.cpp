#include <bits/stdc++.h>

using namespace std;

/*
先捋清楚题意，太复杂了 
有 m 个地铁站 
每个地铁站有一个站厅，从地铁口走到站厅需要花时间 w_v，回来的时间也是 w_v

地铁线路有 n 条，每条给出 k 个点，每个点是一个地铁站，意思是按照这个顺序走地铁站
如果你需要从这条线路上的某个地铁站站厅走到站台需要 t_{i, j} 的时间

这里意思是，从地铁口先走到站厅，然后从站厅走到某个站台才能上地铁

每个地铁站最多有 d 条线路通过

然后题目说地铁网络连通，通过给定的线路能让任何两个地铁站互相到达，即给的是连通图

站内换乘指的是从一条线路的站台先走到站厅，再从站厅走到另一个线路的站台，不用出地铁的门 
从 x 站走到 y 站，其实只有在最开始需要从 x 门口走到站厅，以及最后从 y 站厅走到 y 门口

要最小化的是步行时间，即门口到站台以及站台到站厅的时间，地铁坐多久无所谓的 

我们可以这样建模
对于同一个线路上的站 u 和 v，u 到 v 的时间就是从 u 站厅走到这条线路的站台，然后从这条线路的站台走到 v 站厅的时间
总共给了 500 条线路，n 条 
最坏的情况下，相当于 m 个点，n * m^2 条边 
在这个图上每个询问跑最短路，最后别忘了加上进 x 站厅和出 y 站厅的时间就行
前 8 个点中，m <= 400，所以至多就是 400 个点的稠密图
跑 floyd 即可，然后询问是 O(1) 的，32 分，记得加起点和终点的进出站代价 
这个做法的瓶颈在建图上 
注意到这个题并不多测

考虑性质 A，可以认为都是孤立点或者直连边
孤立点不用考虑，直连边的话，结合 m <= 1000，点数不多，边数也是 O(m) 级别的
那我直接用 O(mlogm) 跑 m 遍单源最短路就行了
然后回答 1e5 次询问
但是可能超时，最好先想想别的做法

考虑性质 B，说站厅走到站台的时间都相等，那相当于我最小化站内换乘次数就好了
那我们不妨把线路当成是点，对线路连边
相当于看，x 和 y 分别在那个线路上，然后我 BFS 一遍就行了 

有个测试点 n <= 2，那么我们关心一个事情
如果两个点在同一个线路上，那我不需要换乘即可
如果两个点不在同一个线路上，我应该选这两条线路交点里面最便宜的那个换乘 
这样我需要看哪些点同时在两条线路上
然后找到 t 最小的那个，所有的换乘就都选这个点换即可了
感觉是使用两个数组或者 set 搞一下就好了 

注意到一个条件，每个地铁站至多有 d 条线路经过，d = 20，并不大
意味着在这个位置有 400 种不同的换乘方案 
通过性质 B，我们已经几乎做出来正解了
我们考虑对线路连边
枚举每个地铁站，然后看哪些线路经过它 
两个线路之间的边权，就是这两个 t 的值相加
这样我们的图有 n 个点，至多 n^2 条有用边(保留小的)，但实际上会建 d^2 * m 条边 
代入数据，就是 500 个点的稠密图
在这个稠密图上跑 floyd，得到全员最短路
然后对于每个询问，查 x 和 y 分别属于哪个线路
这样会产生 O(d^2) 种选择
对每种选择去查最短路，找到最小的那个就行了
回答复杂度 O(d^2 * q)，计算量应该可以接受 
总复杂度 O(d^2 * (m + q)) 

这个题常数应该严格控制一下，只给了 1 秒，有过不了的风险 
感觉可能需要优化一下建图部分，如果是 O(n^2) 建图就从容很多，但我们先放一放 
*/

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef unsigned long long ULL;

const int M = 5e5 + 10;
const int N = 510;
const LL INFLL = 2e18;

LL c, n, m, d, q, w[M];
LL x[M], y[M];
// 每条路的信息 
vector<vector<PLL>> road(N);

namespace subtask_all {
	// 经过 i 点的所有线路编号以及耗时 
	vector<vector<PLL>> pass_road(M);
	LL len[N][N];
	
	void solve() {
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < road[i].size(); j++) {
				LL id = road[i][j].first;
				LL road_id = i;
				pass_road[id].push_back({road_id, road[i][j].second});
			}
		}	
		
		memset(len, 0x3f, sizeof len);
		for (int i = 1; i <= n; i++) {
			len[i][i] = 0;
		}
		
		// 对于每个地铁站，做 d^2 的连边 
		for (int i = 1; i <= m; i++) {
			for (int p = 0; p < pass_road[i].size(); p++) {
				for (int q = p + 1; q < pass_road[i].size(); q++) {
					LL u = pass_road[i][p].first, t1 = pass_road[i][p].second;
					LL v = pass_road[i][q].first, t2 = pass_road[i][q].second;
					len[u][v] = min(len[u][v], t1 + t2);
					len[v][u] = min(len[v][u], t1 + t2);
				}
			}
		}
		
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					len[i][j] = min(len[i][j], len[i][k] + len[k][j]);
				}
			} 
		}
		
		for (int i = 1; i <= q; i++) {
			LL u = x[i], v = y[i];
			LL res = INFLL;
			// 枚举 u 所在的 d 条线路，以及 v 所在的 d 条线路 
			for (int j = 0; j < pass_road[u].size(); j++) {
				for (int k = 0; k < pass_road[v].size(); k++) {
					int id1 = pass_road[u][j].first;
					int id2 = pass_road[v][k].first;
					res = min(res, len[id1][id2] + w[u] + w[v] + pass_road[u][j].second + pass_road[v][k].second);
				}
			}
			cout << res << "\n";
		}
	}
}

void solve() {
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			LL a, t;
			cin >> a >> t;
			road[i].push_back({a, t});
		}
	}
	
	for (int i = 1; i <= q; i++) {
		cin >> x[i] >> y[i];
	}
	
	subtask_all::solve();
}

int main() {
	#ifndef LOCAL_TEST
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	#endif
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T = 1;
	// cin >> T;
	while (T--) {
		solve();
	} 
	
	return 0;
} 
