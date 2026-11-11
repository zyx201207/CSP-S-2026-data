#include <bits/stdc++.h>

using namespace std;

const int maxn = 5005;
#define LL long long
using pii = pair <int, int>;

int c, T, n;
LL x[maxn], d;
vector <int> g[maxn];
int dis[maxn][maxn];
int cnt[maxn][maxn];
bool vis[maxn];

inline int __bound(int i) {
	int l = 1, r = n, mid, ans = 0;
	for (; l <= r; ) {
		mid = (l + r) / 2;
		x[mid] <= x[i] + d ? l = (ans = mid) + 1 : r = mid - 1;
	}
	return ans;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	for (cin >> c >> T; T; T --) {
		cin >> n >> d;
		for (int i = 1; i <= n; i ++) cin >> x[i];
		for (int i = 1; i <= n; i ++) g[i].clear();
		for (int i = 1; i <= n; i ++) {
			int far = __bound(i);
			for (int j = i + 1; j <= far; j ++) {
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
		
		if (n <= 5000) {
			priority_queue <pii, vector <pii>, greater <pii>> q;
			queue <int> qq;
			for (int s = 1; s <= n; s ++) {
				for (int i = 1; i <= n; i ++) {
					dis[s][i] = 1e9;
					vis[i] = 0;
					cnt[s][i] = 0;
				}
				vis[s] = 1;
				dis[s][s] = 0;
				q.push({0, s});
				
				while (!q.empty()) {
					int u = q.top().second;
					q.pop();
					for (int v : g[u]) {
						if (dis[s][v] > dis[s][u] + 1) {
							dis[s][v] = dis[s][u] + 1;
							if (!vis[v]) {
								vis[v] = 1;
								q.push({dis[s][v], v});
							}
						}
					}
				}
				
				for (int i = 1; i <= n; i ++) vis[i] = 0;
				qq.push(s);
				vis[s] = cnt[s][s] = 1;
				while (!qq.empty()) {
					int u = qq.front();
					qq.pop();
					for (int v : g[u]) {
						if (dis[s][v] == dis[s][u] + 1) {
							cnt[s][v] += cnt[s][u];
							if (!vis[v]) {
								qq.push(v);
								vis[v] = 1;
							}
						}
					}
				}
			}
			
			int ans = 0;
			for (int i = 1; i < n; i ++) {
				for (int j = i + 1; j <= n; j ++) {
					if (cnt[i][j] == 2) ans ++;
				}
			}
			cout << ans << '\n';
			continue;		
		}
		
		int found = 0, ans = 0;
		for (int i = 1; i <= n; i ++) {
			if (g[i].size() == n - 1) {
				found = i;
				break;
			}
		}
		if (!found) {
			cout << 0 << '\n';
			continue;
		}
		
		for (int i = 1; i <= n; i ++) {
			queue <int> q;
			set <int> s;
			for (int v : g[i]) {
				if (v <= i) continue;
				if (v != found && s.find(v) == s.end()) {
					s.insert(v);
					q.push(v);
				}
			}
			int cnt = 0;
			while (!q.empty()) {
				int u = q.front();
				q.pop();
				for (int v : g[u]) {
					if (v <= u) continue;
					if (v != found && s.find(v) == s.end()) {
						s.insert(v);
						cnt ++;
					}
				}
			}
			ans += cnt;
		}
		
		cout << ans << '\n';
	}
	
	return 0;
}
