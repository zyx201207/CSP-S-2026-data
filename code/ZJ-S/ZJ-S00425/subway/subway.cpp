#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 505, M = 5e5 + 5;
int c, n, m, d, q, w[M], k, dis[M + N];
bool vis[M + N];
struct edge{
	int to, len;
	bool operator<(const edge&x)const{
		return len > x.len;
	}
};
vector<edge>g[N + M];
void dijkstra(int s) {
	memset(dis, 0x3f, sizeof dis);
	memset(vis, 0, sizeof vis);
	priority_queue<edge>pq;
	dis[s] = 0, pq.push({s, 0});
	while (!pq.empty()) {
		edge p = pq.top();
		pq.pop();
		int u = p.to;
		if (vis[u])continue;
		vis[u] = 1;
		for (int i = 0; i < g[u].size(); i++) {
			int v = g[u][i].to, w = g[u][i].len;
			if (dis[v] > dis[u] + w)
				dis[v] = dis[u] + w, pq.push({v, dis[v]});
		}
	}
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int x, y;
			cin >> x >> y;
			g[i + m].push_back({x, y});
			g[x].push_back({i + m, y});
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		dijkstra(x);
		cout << dis[y] + w[x] + w[y] << '\n';
	}
	return 0;
}
/*
在一开始
当初我还是
一个天真而又爱哭的孩子
十年之后
终于才明白
只要全力以赴就无所谓失败

转眼间
一切都已改变
新的起点新的世界就在眼前
受过伤
也流过了眼泪
为了梦想疯狂这一次又怎样

奔跑吧
骄傲的少年
年轻的心里面
是坚定的信念
燃烧吧
骄傲的热血
胜利的歌我要再唱一遍

世界之大
总想要去飞
就算满身伤痕也不曾后悔
无人喝彩
依然在期待
雨后的彩虹它是那样的精彩

转眼间
一切都已改变
新的起点新的世界就在眼前
受过伤
也流过了眼泪
为了梦想疯狂这一次又怎样

奔跑吧
骄傲的少年
年轻的心里面
是坚定的信念
燃烧吧
骄傲的热血
胜利的歌我要再唱一遍

rap

奔跑吧
骄傲的少年
年轻的心里面
是坚定的信念
燃烧吧
骄傲的热血
胜利的歌我要再唱一遍

胜利的歌我要再唱一遍
                   -- 南征北战《骄傲的少年》
致屏幕前的你			 
*/ 
