#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define LCF using
#define pass namespace
#define CSP_S std
#define PII pair<ll, ll>
LCF pass CSP_S;
LCF ll = long long;
const int N = 505, M = 500005;
int w[M],k[N], conum[M];//conum记录与每个点相连的线路个数 
vector<PII> sub[N];//每条线的点和距离们 
vector<PII> graph[N + M];//把线路当成点来建图 ,线路点追加在正常点后面 
//floyd用 
int udnum = 0;//有效点个数 
vector<PII> dor[N * 2];//本来的边，先线路再真实站台 
ll dist[N * 2][N * 2];//全源最短路 
void Dijkstra(int s) {
	priority_queue<PII> q;
	q.push({0, s});
	dist[s][s] = 0;
	while (!q.empty()) {
		int u = q.top().second;
		q.pop();
		for (auto edge : dor[u]) {
			int v = edge.second, w = edge.first;
			if (dist[s][u] + w < dist[s][v]) {
				dist[s][v] = dist[s][u] + w;
				q.push({dist[s][v], v}); 
			}
		}
	}
	return;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int tasknum, n, m, d, q;
	cin >> tasknum >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i ++) {
		cin >> k[i];
		for (int j = 1; j<= k[i]; j ++) {
			int dot, len;
			cin >> dot >> len;
			sub[i].push_back({len, dot});//先权再点 
			//连边
			int dt = sub[i][j - 1].second;
			graph[m + i].push_back({len, dt});
			graph[dt].push_back({len, m + i}); 
			conum[dt] ++;
		}
	}
	//	验证见图 
//	for (int i = 1; i <= n + m; i ++) {
//		cout << i << ':';
//		for (auto j : graph[i]) {
//			cout << j.second << ' ';
//		}
//		cout << '\n';
//	}
	//存有效点
	for (int i = 1; i <= m; i ++) { 
		if (conum[i] == 1) continue;
		udnum ++;
		for (auto xl : graph[i]) {
			int dt = xl.second;
//			cout << dt << ' ' << n + udnum << ' ' << xl.first << '\n';
//上面一行是验证 
			dor[dt - m].push_back({xl.first, n + udnum});
			dor[n + udnum].push_back({xl.first, dt - m});
		}
	} 
//	for (int i = 1; i <= n + udnum; i ++) {
//		cout << i << "ovo";
//		for (auto j : dor[i]) {
//			cout << j.second << ' ';
//		}
//		cout << '\n';
//	}
	memset(dist,0x3f,sizeof(dist));
	for (int i = 1; i <= n; i ++) {
		Dijkstra(i);
//		for (int j = 1; j <= n; j ++) {
//			cout << dist[i][j] << ' ';
//		}
//		cout << '\n';
	}
	while (q --) {
		int u, v;
		cin >> u >> v;
		ll minn = 1e18;
		for (auto eu : graph[u]) {
			int lcf = eu.second, lu = eu.first;
			for(auto ev : graph[v]) {
				int hmy = ev.second, lv = ev.first;
//				cout << lcf << ' ' << hmy << '\n';
//				cout << lu << ' ' << lv << ' ' << dist[lcf - m][hmy - m] << '\n';
				minn = min(minn, lu + lv + dist[lcf - m][hmy - m]);
			}
		}
		cout << minn + w[u] + w[v] << '\n';
	}
	return 0;
}
/*
T1这么顺利很是意外，15:05开题 
我还没读明白题旁边这哥们写完T2了 
大概就是有一些地铁站，进出站要花一些时间；
有若干地铁线路，坐地铁不需要时间，换线需要时间，不同站台不同线时间不同
给定起点终点问最短时间
不打算拿满了，爆搜  
发现m小于地铁站经过的总数那么地铁一定大于一条 
把线路看成点？！ 
把线路和站台都看成点，他们之间站厅到站台的距离才看成真正的边 
我们只处理线路之间的全源最短路，
然后处理询问
然后对于每个询问，枚举与起点终点直接相连的线路取最小值
还有一条十分重要的性质： 由于站台之间没有边相连，
最短路搜索只需要考虑那些与两个以上边相连的站台，可以压缩点数
我们注意到Dijkstra跑一趟是……多少来着,nlogm，n是边数
那这样每个点跑Dijkstra就是mnlogm，远好于Floyd.因为n,m都是1000量级 
那就写Dij 
欸叕没pop 
16:34 Dij对了 
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
