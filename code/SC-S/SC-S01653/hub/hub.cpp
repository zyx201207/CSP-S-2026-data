/*
给定一棵树和 k
选定 k 个关键点，连成不超过两个连通块
使得距离关键点最远的点尽量近
对于 n <= 10 的，枚举所有选点情况 15
对于 k = 2 的，枚举选点情况
考虑树形 DP
dp[i][j][0/1][k][0/1/2] 表示
i 的子树内选了 j 个点，且 i 是否选择，且最近选择距离根为 k，且连通块个数为 0/1/2 的最远距离
考虑转移，在前缀子树内加入一个新的子树
不太容易，还是考虑先打会的
可以考虑二分
选择一条边断掉，枚举左右点数量，然后转为简单问题
对于只有一个点的情况，肯定是直径长度 / 2
先钦定直径中点为必选点，然后一层层剥去叶子
剥去几层答案就是多少
复杂度 n * n * n，15 分，我直接拼了
30 分
*/
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2e6 + 5;
int C, T, n, k, mnd[N], ans;
bool vis[N];
vector<int> v[N];
void dfs1(int x, int dit, int fa) {
	mnd[x] = min(mnd[x], dit);
	for (int y : v[x])
		if (y != fa)
			dfs1(y, dit + 1, x);
}
int ban, mxd, idx, pr[N], a[N];
void dfs(int x, int fa, int d, bool rec) {
	if (rec) a[d] = x;
	if (d >= mxd) {
		mxd = d, idx = x;
		if (rec)
			for (int i = 1; i <= d; ++i)
				pr[i] = a[i];
	}
	for (int y : v[x])
		if (y != fa and y != ban)
			dfs(y, x, d + 1, rec);
}
int du[N], fu[N], sz[N];
vector<int> vec;
void gps(int x, int fa) {
	du[x] = 0, vec.push_back(x), fu[x] = fa, sz[x] = 1;
	for (int y : v[x])
		if (y != fa and y != ban)
			gps(y, x), ++du[x], sz[x] += sz[y];
}
queue<pair<int, int> > q;
int solve(int rt, int siz) {
	int ret = 0;
	vec.clear();
	while (q.size()) q.pop();
	for (int i = 1; i <= n; ++i) sz[i] = du[i] = fu[i] = 0;
	
	mxd = 0, idx = 0, dfs(rt, 0, 0, 0);
	mxd = 0, dfs(idx, 0, 1, 1);
	idx = pr[(mxd + 1) / 2];
	gps(idx, 0), siz = min(siz, sz[idx]);
	
	for (int i : vec)
		if (!du[i]) q.push({i, 1});
	for (int i = 1; i <= sz[idx] - siz and q.size(); ++i) {
		pair<int, int> x = q.front();
		q.pop(), ret = max(ret, x.second);
		if (fu[x.first]) {
			--du[fu[x.first]];
			if (du[fu[x.first]] == 0)
				q.push({fu[x.first], x.second + 1});
		}
	}
	return ret;
}
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> C >> T;
	while (T--) {
		cin >> n >> k;
		for (int i = 1; i <= n; ++i) v[i].clear();
		for (int i = 1, x, y; i < n; ++i)
			cin >> x >> y,
			v[x].push_back(y),
			v[y].push_back(x);
		ban = 0, ans = solve(1, k);
		for (int x = 1; x <= n; ++x) {
			if (n > 100 and x == 20) break;
			for (int y : v[x]) {
				if (x > y) continue;
				// x, y 边断掉
				for (int j = 1, tmp; j < k; ++j) {
					ban = x, tmp = solve(y, j);
					if (n > 100 and tmp >= ans) continue;
					ban = y, ans = min(ans, max(tmp, solve(x, k - j)));
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}