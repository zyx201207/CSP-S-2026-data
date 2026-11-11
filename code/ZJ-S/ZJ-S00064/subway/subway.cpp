// 好难懂。。w
// 20min才读懂题目意思awa 
// 图论建模？
// 怎么优化图呢？
// 还是只会 60pts
// 继续给我想！！！ 
// 建出来的图点的度数除那 500 之外都小于 20
// 结合去年来看这个性质有大用
// 有意思，先预处理每条线之间的最短路不就行了？！
// T2 也是秒切，思路思考时间小于读题时间（ 
// 16:00 切T2，手感不错 
// 建图复杂度 20^2 * m + n^3
// 咦怎么没过
// woc floyd 写错了 ok 过了 
#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 6;
long long INF = 1e17; 
int cl, n, m, d, q, k;
long long w[N], dis[505][505];
struct Node {
	int to; long long v;
} ; 
vector <Node> p[N];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &cl, &n, &m, &d, &q);
	for (int i = 1; i <= m; ++i) scanf("%lld", &w[i]);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &k);
		for (int j = 1; j <= k; ++j) {
			int a; long long t;
			scanf("%d%lld", &a, &t);
			p[a].push_back({i, t});
		} 
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			dis[i][j] = INF;
	for (int i = 1; i <= m; ++i) {
		for (int j = 0; j < p[i].size(); ++i) {
			long long vj = p[i][j].v;
			int toj = p[i][j].to;
			for (int k = j + 1; k < p[i].size(); ++k) {
				long long vk = p[i][k].v;
				int tok = p[i][k].to;
				dis[toj][tok] = dis[tok][toj] = min(dis[tok][toj], vj + vk);
			}
		}
	}
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				if (dis[i][k] != INF && dis[k][j] != INF)
					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	while (q--) {
		int x, y;
		scanf("%d%d", &x, &y);
		long long ans = INF;
		for (int i = 0; i < p[x].size(); ++i) {
			for (int j = 0; j < p[y].size(); ++j) {
				int toi = p[x][i].to, toj = p[y][j].to;
				long long vi = p[x][i].v, vj = p[y][j].v;
				if (toi == toj) ans = min(ans, vi + vj);
				if (dis[toi][toj] == INF) continue ;
				ans = min(ans, vi + vj + dis[toi][toj]);
			}
		}
		printf("%lld\n", ans + w[x] + w[y]);
	}
	return 0;
}
