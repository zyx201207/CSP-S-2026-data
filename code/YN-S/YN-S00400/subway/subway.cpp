#include <bits/stdc++.h>
using namespace std;
const int M = 500005;
long long c, n, m, d, q, w[M], k[M], a, t, x, y, ans, minn, top;

struct node {
	long long a, t;
};



vector<node>v[M], e[505];
long long dis[505][505];
bool vis[505];

void dijk(int st) {
	memset(vis, 0, sizeof(vis));
	memset(dis[st], 0x3f, sizeof(dis[st]));
	dis[st][st] = 0;

	priority_queue<long long>q;

	for (auto i : e[st]) {
		//t fr to
		q.push(i.t * 1000000 + st * 1000 + i.a);
	}

	while (!q.empty()) {
		long long now = q.top();
		long long nowfr = (now % 1000000) / 1000;
		long long nowto = now % 1000;
		long long nowt = now / 1000000;
		//cout << now << '\n';
		q.pop();

		if (vis[nowfr] == 1) {
			continue;
		}

		vis[nowfr] == 1;

		if (dis[st][nowto] > dis[st][nowfr] + nowt) {
			dis[st][nowto] = dis[st][nowfr] + nowt;

			for (auto i : e[nowto]) {
				q.push(i.t * 1000000 + nowto * 1000 + i.a);
			}
		}
	}
}

long long read() {
	long long c = 0, r = 0;

	while (1) {
		r = getchar();

		if (r == ' ' || r == '\n')
			return c;
		c *= 10;
		c += r - '0';
	}

}

void write(long long s) {
	long long c = 0;
	long long s1 = s, cnt = 0;
	int ppt[20] = {0};

	while (s) {
		ppt[++cnt] = s % 10;
		s /= 10;

	}



	for (int i = cnt; i >= 1; i--) {

		putchar(ppt[i] + '0');
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0), cout.tie(0);
	c = read();
	n = read();
	m = read();
	d = read();
	q = read();

	//cin >> c >> n >> m >> d >> q;

	for (int i = 1; i <= m; i++) {

		w[i] = read();
		//cin >> w[i];
	}

	for (int i = 1; i <= n; i++) {

		k[i] = read();
		//cin >> k[i];

		for (int j = 1; j <= k[i]; j++) {

			a = read();
			t = read();
			//cin >> a >> t;
			v[a].push_back({i, t});
		}
	}

	for (int i = 1; i <= m; i++) {

		if (v[i].size() <= 1)
			continue;

		for (int x = 0; x < v[i].size(); x++) {

			for (int y = 0; y < v[i].size(); y++) {

				if (x == y)
					continue;
				e[v[i][x].a].push_back({v[i][y].a, v[i][x].t + v[i][y].t});
			}
		}
	}

//	for (int i = 1; i <= n; i++) {
//
//		for (node j : e[i]) {
//			cout << i << "to" << j.a << ":" << j.t << "\n";
//		}
//	}

	for (int i = 1; i <= n; i++) {

		dijk(i);
	}

//	for (int i = 1; i <= n; i++) {
//
//		for (int j = 1; j <= n; j++) {
//
//			cout << dis[i][j] << ' ';
//		}
//
//		cout << '\n';
//	}
//	for (int i = 1; i <= m; i++) {
//
//		cout << v[i].size() << ' ';
//	}

	//cout << "Q:" << q << endl;

	while (q--) {
		minn = 1e18;
		x = read();
		y = read();
		//cin >> x >> y;

		for (int i = 0; i < v[x].size(); i++) {

			for (int j = 0; j < v[y].size(); j++) {

//				cout << "ij:" << v[x][i].a << ' ' << v[y][j].a << '\n';
//				cout << "dis:" << dis[v[x][i].a][v[y][j].a] << "\n";
//				cout << "t1t2:" << v[x][i].t << " " << v[y][j].t << '\n';
				minn = min(minn, dis[v[x][i].a][v[y][j].a] + v[x][i].t + v[y][j].t);

			}
		}

		write(minn + w[x] + w[y]);
		cout << '\n';
		//cout << minn + w[x] + w[y] << '\n';

	}

	return 0;
}
