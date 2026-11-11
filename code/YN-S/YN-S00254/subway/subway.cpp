#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1005;
int c, n, m, d, q;
int w[N], t[N][N], a[N][N], vis[N];
vector<int>e[N];

struct node {
	int a;
	vector<int>dir;
};

int sove(vector<int>a) {
	int sum = 0;
	for (int i = 0; i < a.size(); i++) {
		sum += w[a[i]], sum += t[i][a[i]];
	}
	return sum * 2;
}

void bfs(int st, int en) {
	queue<node>q;
	vector<int>now;
	q.push({st, now});
	memset(vis, 0, sizeof vis);
	vis[st] = 1;
	for (; !q.empty();) {
		auto now = q.front();
		q.pop();
		if (now.a == en) {
			cout << sove(now.dir) << "\n";
			return;
		}
		for (auto c : e[now.a]) {
			if (vis[c] == 0) {
				vis[c] = 1;
				vector<int>nex = now.dir;
				nex.push_back(c);
				q.push({c, nex});
			}
		}
	}
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)cin >> w[i];
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> a[i][j] >> t[i][j];
			e[i].push_back(a[i][j]);
		}
	}
	for (int i = 1; i <= q; i++) {
		int x, y;
		cin >> x >> y;
//		cout << x *y + x + y << "\n";
		bfs(x, y);
	}
	return 0;
}