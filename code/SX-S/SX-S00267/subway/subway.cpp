#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using PIL = pair<int, ll>;

const int MAXN = 505;
const int MAXM = 500005;
const int MAXK = 500005;
const int MAXD = 25;
const int MAXQ = 100005;

int C, n, m, d, q;
int z[MAXK];
ll w_s[MAXM];
ll t[MAXN][MAXK / 2];

vector<int> belong[MAXD]; //地铁站归属的线路
vector<int> rt[MAXK]; //某线路的所有站点

struct S {
	int to, nxt;
	ll w;
} edge[MAXN * MAXD * 2];
int head[MAXN], cnt;

void add(int u, int v, ll w) {
	cnt++;
	edge[cnt].to = v;
	edge[cnt].w = w;
	edge[cnt].nxt = head[u];
	head[u] = cnt;
}

ll dis[MAXN];
bool vis[MAXN];

void dijkstra(int s) {
	priority_queue<PIL, vector<PIL >, greater<PIL > > pq;

	memset(dis, 0x3f, sizeof dis);
	memset(vis, 0, sizeof vis);

	dis[s] = 0;
	pq.push({s, dis[s]});

	while (!pq.empty()) {
		int u = pq.top().first;
		pq.pop();

		if (vis[u])
			continue;
		vis[u] = true;

		for (int i = head[u]; i; i = edge[i].nxt) {
			int v = edge[i].to;
			ll w = edge[i].w;

			if (dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w;
				pq.push({v, dis[v]});
			}
		}
	}
}

int main() {

	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> C >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w_s[i];
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;

		int ct = 1;
		for (int j = 1; j <= 2 * k; j++) {
			if (j % 2 == 1) {
				cin >> z[ct];

				belong[z[ct]].push_back(i);
				rt[i].push_back(z[ct]);

				ct++;
			} else {
				cin >> t[i][z[ct - 1]];
			}
		}
	}

	for (int i = 1; i <= m; i++) {

		for (int a = 0; a < int(belong[i].size() - 1); a++) {
			for (int b = a + 1; b < int(belong[i].size()); b++) {
				int x = belong[i][a];
				int y = belong[i][b];
				ll w = t[a][i] + t[b][i];

				add(x, y, w);
				add(y, x, w);
			}
		}
	}

	for (int i = 1; i <= q; i++) {
		int x, y;
		cin >> x >> y;

		ll ans = INT_MAX;
		ll tot = 0;
		for (int s : belong[x]) {
			dijkstra(s);

			tot += w_s[x] + t[s][x];
//			cout << "tot:" << tot << endl;
			for (int e : belong[y]) {
				tot += dis[e];
//				cout << "tot:" << tot << endl;
				tot += t[e][y] + w_s[y];
//				cout << "tot:" << tot << endl;

				ans = min(ans, tot);
			}
		}

		cout << ans << "\n";
	}

	return 0;
}
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2

//好无助，这道题我明明有思路，到最后还是调试不出来啊
//我这段时间还不够努力，付出的还是不够
//我还有机会吗
//高一文化课压力也很大啊
//放弃的决定很艰难，但我不能逃避
//能去NOIP，就去见一见
//进不了，我还是会过好原本的生活
//不论怎样，我只管尽力做好我喜欢的事情，以及我应该做的事情