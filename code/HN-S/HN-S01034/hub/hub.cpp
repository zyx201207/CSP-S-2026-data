#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 15;
vector<int> g[N];
bool vis[N];
int dis[N][N], p[N], ans, n, k;
void dfs(int x, int ba, int gen, int sum) {
	dis[gen][x] = sum;
	for (int i : g[x]) {
		if (i != ba) {
			dfs(i, x, gen, sum + 1);
		}
	}
}
int find(int x) {
	if (p[x] != x) {
		p[x] = find(p[x]);
	}
	return p[x];
}
void DFS(int x, int sum) {
	if (x == n + 1) {
		if (sum == k) {
			for (int i = 1; i <= n; i++) {
				p[i] = i;
			}
			for (int i = 1; i <= n; i++) {
				if (vis[i]) {		
					for (int j : g[i]) {
						if (vis[j]) {
							int fx = find(i), fy = find(j);
							if (fx != fy) {
								p[fx] = fy;
							}
						}
					}
				}
			}
			set<int> s;
			for (int i = 1; i <= n; i++) {
				if (vis[i]) {
					s.insert(find(i));
				}
			}
			if (s.size() <= 2) {
				int sum = 0;
				for (int i = 1; i <= n; i++) {
					int qwq = LONG_LONG_MAX;
					for (int j = 1; j <= n; j++) {
						if (vis[j]) {
							qwq = min(qwq, dis[i][j]);
						}
					}
					sum = max(sum, qwq);
				}
				ans = min(ans, sum);
			}
		}
		return;
	}
	vis[x] = 0;
	DFS(x + 1, sum);
	vis[x] = 1;
	DFS(x + 1, sum + 1);
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		ans = LONG_LONG_MAX;
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			g[i].clear();
		}
		for (int i = 1; i < n; i++) {
			int x, y;
			cin >> x >> y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		for (int i = 1; i <= n; i++) {
			dfs(i, 0, i, 0);
		}
		DFS(1, 0);
		cout << ans << '\n';
	}
	return 0;
}
/*
还有十分种就结束了
回顾一下我的 OI 生涯吧
看看联考吧，打这玩意纯吃屎，搞不懂为什么教练要我们打
预估的是100+100+48+15=263
希望不要挂分
我也没有什么能留下的了
来听歌吧
哦对了可能写不完 

反乌托邦

反乌托邦中的争夺
把愿望敲碎成粉末
心灵也被挂上了锁
看不清灯火

但我还想做些什么
其实还想要说很多
请你等等我
请你等等我

两块五的签字笔
东拼西凑的词句
妄想用它拯救你
顺便拯救我自己

只因为
你那渴望自由的心脏
困在一张没有空隙的网
我们的周围并非没光亮
只是太阳耀眼将我们灼伤

在这个世界难免会迷茫
但别再把小刀在身上
至少我还在为你而歌唱
在黑暗漫长的反乌托邦

即便
我们
都在
这黑暗漫长的反乌托邦

后面的没时间写了就不写了 QWQ 
								——2026.10.31 
*/
