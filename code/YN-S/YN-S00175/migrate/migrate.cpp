//hy
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 10;
int n, d, C, T;
int a[N];
vector<int>e[N];
int dis[N], f[N];
bool bk[N];

void djst(int x) {
	f[x] = 1;
	dis[x] = 0;
	priority_queue<pair<int, int>>q;
	q.push({0, x});
	while (q.size()) {
		int tmp = q.top().second;
		q.pop();
		if (bk[tmp])
			continue;
		bk[tmp] = 1;
		for (int i = 0; i < e[tmp].size(); i++) {
			int v = e[tmp][i];
			if (dis[v] > dis[tmp] + 1) {
				dis[v] = dis[tmp] + 1;
				f[v] = f[tmp];
				q.push({-dis[v], v});
			} else if (dis[v] == dis[tmp] + 1) {
				f[v] += f[tmp];
			}
		}
	}
}

void slove() {
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (abs(a[i] - a[j]) > d)
				break;
			e[i].push_back(j);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			bk[j] = f[j] = 0;
			dis[j] = 1e18;
		}
		djst(i);
		for (int j = i + 1; j <= n; j++) {
			if (f[j] == 2) {
				ans++;
			}
		}
	}
	cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> C >> T;
	while (T--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			e[i].clear();
			cin >> a[i];
		}
		slove();
	}
	return 0;
}
