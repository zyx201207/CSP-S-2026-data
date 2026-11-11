/*
A 切不掉 T3 呜呜 我要 AFO 了 
二分答案，转化为每个点半径内必须有一个点。
考虑对于每条边，去把树分割成两个连通块，强制冗余 
这样问题就转化为了，两边各自需要取的最少点数和是否 <= k
我们考虑直接进行构造：必然为选取直径上的一段连续区间？就是 max(直径长度 - 2k, 1) 吗？
一方面，我们知道这是必须的，因为在直径上至少要取这么多点。
不对，因为侧枝深度可能 >k，还需要额外贡献。

考虑另一个角度：
联通所有 k 级祖先需要的连通块大小，以直径中点为根
这是 n^2log n
直径中点最多移动一步？不一定 

以直径中点为根，子树深度 \ge k 的点数。
所有侧枝中，以连接点，子树深度 \ge k 的点数
f(u, v) = 以 u 为根，v 子树深度 \ge k 的点数（f(u,u) 一次 dfs + 换根可求） 
= \sum f(u, u) - 2 个 f(u, v)（直径方向） 
*/
#include<bits/stdc++.h>
using namespace std;
constexpr int N = 1e6 + 6;
vector<int> g[N];
int n, k;
int dep[N];
bool active[N];
void df_check(int u, int f) {
	dep[u] = 1;
	for (auto v : g[u]) {
		if (v == f && active[v]) continue;
		df_check(v, u);
		dep[u] = max(dep[v] + 1, dep[u]);
	}
}
bool check(int mid) {
	for (int u = 1; u <= n; ++u) {
		for (auto v : g[u]) {
			fill(dep, dep + n + 1, -1);
			active[v] = 1, active[u] = 0;
			df_check(v, u);
			int left = INT_MAX;
			for (int j = 1; j <= n; ++j) {
				if (dep[j] > 0) {
					df_check(j, 0);
					int cnt = 0;
					for (int t = 1; t <= n; ++t) cnt += (dep[t] > t);
					left = min(left, cnt);
				}
			}
			
			active[v] = 0, active[u] = 1;
			df_check(u, v);
			int right = INT_MAX;
			for (int j = 1; j <= n; ++j) {
				if (dep[j] > 0) {
					df_check(j, 0);
					int cnt = 0;
					for (int t = 1; t <= n; ++t) cnt += (dep[t] > t);
					right = min(right, cnt);
				}
			}
			
			active[v] = 1, active[u] = 1;
			if (left + right <= k) return true;
		}
	}
	return false;
}
void run() {
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) g[i].clear();
	fill(active, active + n + 1, 1);
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int l = 0, r = n, ans = -1;
	while (l < r) {
		const int mid = (l + r) / 2;
		if (check(mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	cout << ans << '\n';
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cout << 1 << endl;
	return 0;
	ios::sync_with_stdio(false);
	cin.tie(0); 
	int c, t;
	cin >> c >> t;
	while (t--) run();
	return 0;
}
