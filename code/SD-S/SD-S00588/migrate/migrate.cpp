#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
using db = double;

const int MAXN = 2e6 + 5;

int n;
ll d;
ll x[MAXN];
vector<int> e[MAXN];
int q[MAXN];
int dis[MAXN];
ll cnt[MAXN];

void bfs(int s) {
	int l = 1, r = 0;
	dis[s] = 0;
	cnt[s] = 1;
	q[++r] = s;
	while (l <= r) {
		int u = q[l++];
		if (cnt[u] > 2) continue;
		for (int v : e[u]) {
			if (dis[v] == n + 1) {
				dis[v] = dis[u] + 1;
				cnt[v] = cnt[u];
				q[++r] = v; 
			} else if (dis[v] == dis[u] + 1) {
				cnt[v] += cnt[u];
			}
		}
	}
}

void solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; ++i) {
		cin >> x[i];
		e[i].clear();
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			if (x[j] - x[i] <= d) {
				e[i].push_back(j);
			} else {
				break;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) dis[j] = n + 1;
		bfs(i);
		for (int j = i + 1; j <= n; ++j) {
			if (dis[j] != n + 1 && cnt[j] == 2) ++ans;
		}
	}
	cout << ans << '\n';
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c, t;
	cin >> c >> t;
	while (t--) solve();
}
