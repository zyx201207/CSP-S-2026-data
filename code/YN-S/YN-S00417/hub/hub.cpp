#include <bits/stdc++.h>
using namespace std;
const int N = 205;
int taskid, T, n, k, book[N], vis[N], res;
vector<int>e[N];

inline int read() {
	int f = 1, r = 0;
	char c;
	c = getchar();
	while (c < '0' || c > '9')
		f = -1, c = getchar();
	while (c >= '0' && c <= '9')
		r = r * 10 + c - '0', c = getchar();
	return f * r;
}

void Dfs(int x) {
//	cout << "111\n";
	vis[x] = 1;
	for (auto v : e[x])
		if (book[v] && !vis[v])
			Dfs(v);
}

bool check() {
//	cout << "222\n";
	memset(vis, 0, sizeof(vis));
	int sum = 0;
	for (int i = 1; i <= n; i++)
		if (book[i] && !vis[i])
			Dfs(i), sum++;
	return sum <= 2;
}

int getdis(int x) {
//	cout << "333\n";
	memset(vis, 0, sizeof(vis));
	queue<pair<int, int> >q;
	q.push({x, 0});
	vis[x] = 1;
	while (!q.empty()) {
		int u = q.front().first, c = q.front().second;
		q.pop();
		if (book[u])
			return c;
		for (auto v : e[u])
			if (!vis[v])
				vis[v] = 1, q.push({v, c + 1});
	}
}

void dfs(int sum, int num) {
//	cout << "444\n";
	if (sum == k) {
		if (!check())
			return;
		int t = 0;
		for (int i = 1; i <= n; i++)
			if (!book[i])
				t = max(t, getdis(i));
		res = min(res, t);
		return;
	}
	for (int i = num + 1; i <= n; i++) {
		if (!book[i]) {
			book[i] = 1;
			dfs(sum + 1, i);
			book[i] = 0;
		}
	}
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	taskid = read(), T = read();
	while (T--) {
		n = read(), k = read();
		for (int i = 1, x, y; i < n; i++) {
			x = read(), y = read();
			e[x].push_back(y);
			e[y].push_back(x);
		}
		res = INT_MAX;
		dfs(0, 0);
		cout << res << '\n';
		for (int i = 1; i <= n; i++)
			e[i].clear();
	}
	return 0;
}