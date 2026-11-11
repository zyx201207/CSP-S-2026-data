#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, p;
vector<int> w;
vector<vector<int> > t;
vector<vector<int> > a;
vector<vector<int> > a2;
vector<int> vis;

long long dfs(int start, int end, long long result) {
	if (start == end) {
		return result;
	}
	vis[start] = 1;
	long long num = INT_MAX;
	for (int i = 1; i <= n; i++) {
		if (a2[start][i]) {
			int x = a[i].size();
			for (int j = 1; j < x; j++) {
				if (vis[a[i][j]] == 0) {
					num = min(dfs(a[i][j], end, result + t[i][j] + a2[start][i]), num);
				}
			}
		}
	}
	return result + num;
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> p;
	w.resize(n + 1);
	t.resize(m + 1, vector<int>(1, 0));
	a.resize(m + 1, vector<int>(1, 0));
	a2.resize(n + 1, vector<int>(m + 1, 0));
	vis.resize(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= m; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int x1, y1;
			cin >> x1 >> y1;
			a[i].push_back(x1);
			t[i].push_back(y1);
			a2[a[i][j]][i] = t[i][j];
		}
	}
	for (int i = 1; i <= p; i++) {
		int start, end;
		cin >> start >> end;
		vis.resize(n + 1, 0);
		long long result = 0;
		result = dfs(start, end, result);
		cout << result + w[start] + w[end] << endl;
	}
	return 0;
}