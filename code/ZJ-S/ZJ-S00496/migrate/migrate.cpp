#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 2e6 + 10;
ll test, T, n, d, a[N];
ll dis[8010][8010], cnt[8010][8010];
vector<int> e[N];

void bfs(int st) {
	queue<int> q;
	q.push(st);
	cnt[st][st] = 1;
	dis[st][st] = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int v : e[u]) {
			if (!cnt[st][v]) {
				q.push(v);
				dis[st][v] = dis[st][u] + 1;
				cnt[st][v] += cnt[st][u];
			}
			else if (dis[st][v] == dis[st][u] + 1) {
				cnt[st][v] += cnt[st][u];
			}	
		}											
	}																
}

void solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		e[i].clear();	
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (a[j] - a[i] <= d) {
				e[i].push_back(j);
				e[j].push_back(i);
			}
			else break;
		}
	}
	for (int i = 1; i <= n; i++) bfs(i);
	ll res = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			res += (cnt[i][j] == 2LL);
		}
	}
	cout << res << '\n';
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out" "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> test >> T;
	while (T--) solve();
	return 0;
}
