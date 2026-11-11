#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
#define pii pair<int, int>

inline int read() {
	char ch = getchar();
	int ans = 0, f = 1;
	while (!isdigit(ch)) {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		ans = ans * 10 + ch - '0';
		ch = getchar();
	}
	return ans * f;
}

int c, t, n, d;
int x[N];
vector<int> g[N];
int answer;
int dep[N];
int cnt[N], vis[N];
map<int, int> mp;
int mx;

void bfs(int st) {
	for (int i = 1; i <= n; i++) dep[i] = 0;
	queue<int> q;
	q.push(st);
	dep[st] = 1;
	mp[1] = 1;
	mx = 0;
	while (q.size()) {
		int u = q.front();
		q.pop();
		int len = g[u].size();
		for (int i = 0; i < len; i++) {
			int v = g[u][i];
			if (dep[v]) continue;
			dep[v] = dep[u] + 1;
			mp[dep[v]]++;
			q.push(v);
			mx = max(dep[v], mx);
		}
	}
}

void bfs1(int st) {
	queue<int> q;
	q.push(st);
	while (q.size()) {
		int u = q.front();
		q.pop();
		cnt[u]++;
		int len = g[u].size();
		for (int i = 0; i < len; i++) {
			int v = g[u][i];
			if (dep[v] > dep[u]) {
				q.push(v);
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		if (cnt[i] == 2) answer++;
		cnt[i] = 0;
	}
} 

void solve() {	
	answer = 0;
	mp.clear();
	for (int i = 1; i <= n; i++) dep[i] = 0;
	for (int i = 1; i <= n; i++) {
		g[i].clear();
	}
	n = read(), d = read();
	for (int i = 1; i <= n; i++) x[i] = read();
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (x[j] - x[i] <= d) {
				g[i].push_back(j);
				g[j].push_back(i);
			}
			else break;
		}
	}
	
	for (int i = 1; i <= n; i++) {
		bfs(i);
		bfs1(i);
	}
	
	cout << answer / 2 << '\n';
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	c = read(), t = read();
	
	while (t--) {
		solve();
	}
	
	return 0;
}
