#include<bits/stdc++.h>
#define pii pair<int, int>
#define ls(x) x<<1
#define rs(x) x<<1|1
#define endl '\n'

using namespace std;

const int N = 2e6 + 10;
const int D = 1e18 + 10;

int a[N], d, n, dist[N], cnt[N];
bool vis[N];
map<int, int> mp[N];

int solve(int st, int ed) {
	priority_queue<pii, 
	vector<pii>, greater<pii> > q;
	q.push({0, st});
	for (int i = 1; i <= n; ++i) {
		dist[i] = 0x3f3f3f3f;
		vis[i] = 0;
		cnt[i] = 0;
	}
	dist[st] = 0;
	cnt[st] = 1;
	while (!q.empty()) {
		int u = q.top().second;
		q.pop();
		if (vis[u]) continue;
		else vis[u] = 1;
		for (int v = u + 1; v <= n; ++v) {
			if (abs(a[u] - a[v]) > d) break;
			if (v > n) break;
			if (dist[v] > dist[u] + 1) {
				dist[v] = dist[u] + 1;
				cnt[v] = cnt[u];
				q.push({dist[v], v});
			}
			else if (dist[v] == dist[u] + 1) {
				cnt[v] += cnt[u];
			}
		}
		for (int v = u - 1; v >= 1; --v) {
			if (abs(a[u] - a[v]) > d) break;
			if (v < 0) break;
			if (dist[v] > dist[u] + 1) {
				dist[v] = dist[u] + 1;
				cnt[v] = cnt[u];
				q.push({dist[v], v});
			}
			else if (dist[v] == dist[u] + 1) {
				cnt[v] += cnt[u];
			}
		}
	}
	if (cnt[ed] == 2) return 1;
	else return 0;
}

void work() {
	cin >> n >> d;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n;++j) {
			ans += solve(i, j);
		}
	}
	cout << ans << endl;
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		work();
	}
	return 0;
}

