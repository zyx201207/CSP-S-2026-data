/*
由于 d 是一样的，不可能往前跳

设 r[i] 表示 r 往后跳的可行的最远编号，r 一定单调不减。所以每次都跳 r 一定是最优的。

刻画一下恰好 2 条。

固定起点 i，则合法 j 一定是一段区间。

*/
#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 1e6 + 5;

void init() { // 拜托，多测要清空
	
}

int n;
int r[MAXN];
long long x[MAXN];
vector<int> adj[MAXN];

int bfs(int st) {
	vector<int> d(n + 1, -1);
	vector<unsigned long long> cnt(n + 1, 0);
	
	queue<int> q; d[st] = 0; cnt[st] = 1;
	q.push(st);
	
	while (q.size()) {
		int u = q.front(); q.pop();
		for (auto v : adj[u]) {
			if (d[v] == -1) {
				d[v] = d[u] + 1;
				cnt[v] = cnt[u];
				q.push(v);
			} else {
				if (d[u] + 1 == d[v]) {
					cnt[v] += cnt[u];
				}
			}
		}
	}
	int ans = 0;
	for (int i = st + 1; i <= n; ++i) {
		if (d[i] == -1) break;
		if (cnt[i] == 2) {
			++ans;
		}
	}
	return ans;
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c, T; cin >> c >> T;
	while (T--) {
		long long d; 
		cin >> n >> d;
		for (int i = 1; i <= n; ++i) {
			adj[i].clear();
		}
		for (int i = 1; i <= n; ++i) {
			cin >> x[i];
		}
		for (int i = n, j = n; i >= 1; --i) {
			while (j >= i && x[j] - x[i] > d) --j;
			r[i] = j;
		}
		long long ans = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= r[i]; ++j)
				adj[i].emplace_back(j);
		}
		for (int i = 1; i <= n; ++i) {
			ans += bfs(i);
		}
		cout << ans << '\n';
	}
	return 0;
}
/*
空间开够 / 开大了吗
需要卡常吗
还剩多少时间
*/