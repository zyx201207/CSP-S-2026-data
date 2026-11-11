#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int c, n, m, d;
vector<int> a[500005];
vector<int> line[505];
vector<int> tim[505];
int out[500005];
int t[500005];

int bfs(int s, int e) {
	memset(t, 0x3f, sizeof(t));
	stack<int> q;
	q.push(s);
	int ans = 0x3f;
	while (!q.empty()) {
		int k = q.top();
		q.pop();
		for (int i = 0; i < a[k].size(); i++) {
			for (int j = 0; j < line[i].size(); j++) {
				int next = line[i][j];
				if (next == k)
					continue;
				if (t[next] < t[k] + tim[i][j]) {
					t[next] = t[k] + tim[i][j];
					q.push(next);
				}
				if (next == e) {
					ans = min(ans, t[next]);
				}
			}
		}
	}
	return ans + out[s] + out[e];
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> out[i];
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			int o, p;
			cin >> o >> p;
			line[i].push_back(o);
			tim[i].push_back(p);
			a[o].push_back(i);
		}
	}
	while (q--) {
		int s, e;
		cin >> s >> e;
		cout << bfs(s, e) << "\n";
	}

	return 0;
}