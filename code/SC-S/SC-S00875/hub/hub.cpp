#include <bits/stdc++.h>
#define ll long long
#define rep(i, j, k) for(int i=j;i<=k;i++)
#define Suika 0
using namespace std;
const int N = 5e5 + 10;
int c, t, n, k, dis[N];
vector<int> G[N];
bool vis[N], flag[N];
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(Suika);
	cin.tie(Suika);cout.tie(Suika);
	cin >> c >> t;
	while (t--) {
		cin >> n >> k;
		rep(i, 1, n) G[i].clear();
		rep(i, 2, n) {
			int u, v; cin >> u >> v;
			G[u].push_back(v); G[v].push_back(u);
		}
		if (n <= 10) {
			int res = 1e9;
			for (int msk = 1; msk < (1 << n); msk++) {
				rep(i, 1, n) vis[i] = flag[i] = 0;
				int cnt1 = 0;
				rep(i, 1, n) if (msk & (1 << (i - 1))) {
					flag[i] = 1;
					cnt1++;
				}
				if (cnt1 != k) continue;
				int cnt = 0;
				bool f = 1;
				rep(i, 1, n) {
					if (!vis[i] && flag[i]) {
						cnt++;
						if (cnt > 2) {
							f = 0; break;
						}
						queue<int> q;
						q.push(i); vis[i] = 1;
						while (!q.empty()) {
							int u = q.front(); q.pop();
							for (int v : G[u]) {
								if (!flag[v]) continue;
								if (vis[v]) continue; 
								vis[v] = 1; q.push(v);
							}
						}
					}
				}
				if (!f) continue;
				//	rep(i, 1, n) cout << flag[i] << " ";
				//	cout << "\n";
				queue<int> q;
				rep(i, 1, n) dis[i] = -1;
				rep(i, 1, n) if (flag[i]) {
					dis[i] = 0; q.push(i);
				}
				while (!q.empty()) {
					int u = q.front(); q.pop();
					for (int v : G[u]) {
						if (dis[v] == -1) {
							dis[v] = dis[u] + 1;
							q.push(v);
						}
					}
				}
				//	rep(i, 1, n) cout << dis[i] << " ";
				//	cout << "\n";
				int ans = 0;
				rep(i, 1, n) ans = max(ans, dis[i]);
				res = min(res, ans);
			}
			cout << res << "\n";
		} else {
			int res = 1e9;
			if (k == 1) {
				rep(i, 1, n) {
					queue<int> q;
					q.push(i);
					rep(j, 1, n) dis[j] = -1;
					dis[i] = 0;
					while (!q.empty()) {
						int u = q.front(); q.pop();
						for (int v : G[u]) {
							if (dis[v] == -1) {
								dis[v] = dis[u] + 1;
								q.push(v);
							}
						}
					}
					//	rep(i, 1, n) cout << dis[i] << " ";
					//	cout << "\n";
					int ans = 0;
					rep(l, 1, n) ans = max(ans, dis[l]);
					res = min(res, ans);
				}
			} else {
				rep(i, 1, n) {
					rep(j, i + 1, n) {
						queue<int> q;
						q.push(i); q.push(j);
						rep(l, 1, n) dis[l] = -1;
						dis[i] = 0; dis[j] = 0;
						while (!q.empty()) {
							int u = q.front(); q.pop();
							for (int v : G[u]) {
								if (dis[v] == -1) {
									dis[v] = dis[u] + 1;
									q.push(v);
								}
							}
						}
						//	rep(i, 1, n) cout << dis[i] << " ";
						//	cout << "\n";
						int ans = 0;
						rep(l, 1, n) ans = max(ans, dis[l]);
						res = min(res, ans);
					}
				}
			}
			cout << res << "\n";
		}
	}
	return Suika;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/