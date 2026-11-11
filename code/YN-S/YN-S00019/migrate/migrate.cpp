#include <bits/stdc++.h>
using namespace std;
long long c, t;
long long n, d;
long long zuiduan, ans, cnt;
int x[2000005];

struct node {
	long long wei, step, weii;
};

int bfs(long long s, long long e, int si) {
	queue<node>q;
	q.push({s, 0, si});
	while (!q.empty()) {
		node cur = q.front();
		q.pop();
		if (cur.wei == e) {
			return cur.step;
		}
		int j = 1;
		for (long long i = cur.wei + 1; i <= cur.wei + d; i++) {
			if (x[si + j] == i) {
				j++;
				q.push({i, cur.step + 1, j});
			}
		}
	}
}

int dfs(long long s, long long e, int step, int si) {
	int j = 1;
	for (long long i = s + 1; i <= s + d; i++) {
		if (x[si + j] == i) {
			j++;
			if (i == e && step == zuiduan) {
				ans++;
			}
			dfs(x[i], e, step + 1, si + j);
		}
	}
	return ans;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		for (int i = 1; i < n; i++) {
			for (int j = i + 1; j <= n; j++) {
				zuiduan = bfs(x[i], x[j], i);
				if (dfs(x[i], x[j], 0, i) == 2) {
					cnt++;
				}
			}
		}
		cout  << cnt;
	}

	return 0;
}