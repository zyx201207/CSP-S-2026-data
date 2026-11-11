#include <bits/stdc++.h>
using namespace std;

struct station {
	int num, t;
};

struct node {
	int to, val;
};

struct node1 {
	int to, val;
	friend bool operator > (const node1 a, const node1 b) {
		return a.val > b.val;
	}
};
int c, n, m, d, Q;
int w[500005], len[1005], dis[500005];
bool vis[500005];
vector<station> line[505];
vector<node> mp[500005];
priority_queue<node1, vector<node1>, greater<node1> > q;

void dijk(int s) {
	for (int i = 1; i <= m; i++) {
		dis[i] = 0x7fffffff;
		vis[i] = 0;
	}
	dis[s] = 0;
	node1 tmp = {s, 0};
	vis[s] = 1;
	q.push(tmp);
	while (!q.empty()) {

		int u = q.top().to;
		q.pop();
		if (!vis[u])
			continue;
		vis[u] = 1;
		//cout << mp[u].size() << " ";
		for (int i = 0; i < mp[u].size(); i++) {
			//int p = mp[u][i].to;
			//int a1 = dis[mp[u][i].to];
			//long long a2 = dis[u] + mp[u][i].val;
			if (dis[mp[u][i].to] > 1ll * (dis[u] + mp[u][i].val)) {
				dis[mp[u][i].to] = dis[u] + mp[u][i].val;
				vis[mp[u][i].to] = 1;
				q.push({mp[u][i].to, dis[mp[u][i].to]});
			}
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> Q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
		//cout << w[i] << " ";
	}
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		len[i] = a;
		for (int j = 0; j < len[i]; j++) {
			int b, c;
			cin >> b >> c;
			line[i].push_back({b, c});
			//cout << line[i][j].num << " " << line[i][j].t << "\n";
			if (line[i].size() > 1) {
				for (int k = 0; k < line[i].size(); k++) {
					//cout << line[i][k].t + line[i][j].t << "\n";
					int p = line[i][k].num, r = line[i][j].num;
					mp[line[i][j].num].push_back({line[i][k].num, line[i][k].t + line[i][j].t});
					mp[line[i][k].num].push_back({line[i][j].num, line[i][k].t + line[i][j].t});
				}
			}

		}
	}
	for (int i = 1; i <= Q; i++) {
		int x, y;
		cin >> x >> y;
		dijk(x);
		long long ans = dis[y] + w[x] + w[y];
		cout << ans << "\n";
	}

	return 0;
}