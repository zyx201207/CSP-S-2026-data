#define ll long long
#define _up(i, a, b, c) for (ll i = a; i <= b; i += c)
#define up(i, a, b) _up(i, a, b, 1)
#define _dn(i, a, b, c) for (ll i = a; i >= b; i -= c)
#define dn(i, a, b) _dn(i, a, b, 1)
#define N 5005
const ll INF = 1e15;
ll c, t, n, d, ans, x[N], dist[N][N], cnt[N][N], vis[N][N];
#include <bits/stdc++.h>
using namespace std;
vector <ll> g[N];

void spfa(ll s) {
	up (i, 1, n) {
		dist[s][i] = INF;
		cnt[s][i] = 0;
		vis[s][i] = 0;
	}
	queue<ll> q;
	q.push(s);
	vis[s][s] = 1;
	cnt[s][s] = 1;
	dist[s][s] = 0;
	
	while (!q.empty()) {
		ll u = q.front();
		q.pop();
		vis[s][u] = 0;
		
		for (ll i : g[u]) {
			if (dist[s][i] > dist[s][u] + 1) {
				dist[s][i] = dist[s][u] + 1;
				cnt[s][i] = cnt[s][u];
				
				if (!vis[s][i]) {
					vis[s][i] = true;
					q.push(i);
				}
			} else if (dist[s][i] == dist[s][u] + 1) {
				cnt[s][i] += cnt[s][u];
			}
		}
	}
}

void init() {
	cin >> c >> t;
	
	up (i, 1, t) {
		n = d = ans = 0;
		
		cin >> n >> d;
		
		up (i, 1, n) {
			g[i].clear();
		}
		
		up (j, 1, n) {
			cin >> x[j];
		}
		
		up (j, 1, n) {
			up (k, 1, n) {
				if (j == k) continue;
				if (abs(x[j] - x[k]) <= d) {
					g[j].push_back(k);
				}
			}
		}
		
		up (i, 1, n) {
			spfa(i);
		}
		
		up (i, 1, n) {
			up (j, i + 1, n) {
				if (cnt[i][j] == 2) {
					ans++;
				}
			}
		}
		
		cout << ans << '\n';
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	init();
	return 0;
}