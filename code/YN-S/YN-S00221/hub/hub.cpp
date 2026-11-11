#include <bits/stdc++.h>
using namespace std;
#define int long long
int c, t, n, k, ans, ansans, a[105];
bool b[105], v[105];
vector<int>s[105];

void dfs1(int u, int fa) {
	v[u] = 1;

	for (int i = 0; i < s[u].size(); i++) {

		if (s[u][i] != fa && b[s[u][i]]) {
			dfs1(s[u][i], u);
		}
	}

	return;
}

void dfs2(int u, int fa, int sum) {
	ans = max(ans, sum);

	for (int i = 0; i < s[u].size(); i++) {

		if (s[u][i] != fa && !b[s[u][i]]) {
			dfs2(s[u][i], u, sum + 1);
		}
	}

	return;
}

void dfs(int d, int la) {
	if (d > k) {
		int flag = 0;
		memset(v, 0, sizeof(v));

		for (int i = 1; i < d; i++) {

//			cout << a[i] << " ";
			if (!v[a[i]]) {
				dfs1(a[i], 0);
				flag++;
			}
		}

//		cout << "\n";

		if (flag != 2) {
			return;
		}

		ans = 0;

		for (int i = 1; i < d; i++) {

			dfs2(a[i], 0, 0);
		}

		ansans = min(ans, ansans);
		return;
	}

	for (int i = la; i <= n; i++) {

		a[d] = i;
		b[i] = 1;
		dfs(d + 1, i + 1);
		b[i] = 0;
		a[d] = 0;
	}

	return;
}

signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;

	while (t--) {
		cin >> n >> k;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(s, 0, sizeof(s));

		for (int i = 1; i < n; i++) {

			int u, v;
			cin >> u >> v;
			s[u].push_back(v);
			s[v].push_back(u);
		}

		ansans = INT_MAX;
		dfs(1, 1);
		cout << ansans << "\n";
	}

	return 0;
}
/*
0 3
8 6
4 8
5 8
6 3
3 2
2 1
1 8
7 8
6 5
1 2
2 5
4 5
5 3
3 6
9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9


*/