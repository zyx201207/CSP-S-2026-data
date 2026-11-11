#include <bits/stdc++.h>
#define endl '\n'
#define pr pair<int,int>
using namespace std;
using ll = long long;
const int N = 505, C = 50, M = 20050, D = 25;
int w[M];
int c, n, m, d, T;

int subway(int i) {
	return M + i;
}

struct EDGE {
	int to, nxt, val;
};

vector<EDGE> edge(1, {0, 0, 0});
int cnt = 0, head[M + N + 5];
void add(int u, int v, int ww) {
	++cnt;
	edge.push_back({v, head[u], ww});
	head[u] = cnt;
}
bool vis[M + N];
int dist[M + N];

void dj(int S, int tt) {
	priority_queue<pr, vector< pr >, greater< pr > > q;
	memset(dist, 0x3f, sizeof dist);
	memset(vis, false, sizeof vis);
	dist[S] = 0;
	q.push({0, S});
	while (!q.empty()) {
		if (vis[tt] == 1)
			return;
		int p = q.top().second;
		q.pop();
		if (vis[p] == 1)
			continue;
		vis[p] = 1;
		for (int j = head[p]; j; j = edge[j].nxt) {
			int too = edge[j].to;
			if (dist[p] + edge[j].val < dist[too]) {
				dist[too] = dist[p] + edge[j].val;
				q.push({dist[too], too});

			}

		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> T;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
		//i号站口到站厅的距离
	}
	//
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int stop, tim;
			cin >> stop >> tim;
			add(subway(i), stop, tim);
			add(stop, subway(i), tim);
		}
	}

	while (T--) {
		int x, y, ans = 0;
		cin >> x >> y;
		dj(x, y);
		ans = dist[y];
		ans += w[x] + w[y];
		cout << ans << endl;
	}
	return 0;
}
//priority_queue
//Oct31==Dec25 有趣的密码
//检查RECE 检查数据量 检查耗时 检查freopen
//man!忘了DJ咋写了，现场推了半天
//正在手搓最短路TvT
//超时了，也许需要记忆化？