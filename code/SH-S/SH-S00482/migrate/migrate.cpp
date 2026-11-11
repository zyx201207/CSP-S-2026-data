#include <bits/stdc++.h>
using namespace std;
struct node {
	int x, step;
};
int c, t, n, d, cnt;
int a[2000005], diff[2000005], dp[2000005];
bool vis[2000005];
void bfs(int r) {
	int ans = INT_MAX;
	queue<node> q;
	q.push(node{1, 0});
	vis[1] = 1;
	while (!q.empty()) {
		node now = q.front();
		q.pop();
		if (now.x == r) {
			if (now.step <= ans) {
				dp[r]++;
			} else {
				return;
			}
		}
		for (int i = 1; i <= d; i++) {
			if (i < diff[now.x]) {
				continue;
			}
			int nx = now.x + i / diff[now.x];
			if (nx > n) {
				continue;
			}
			q.push(node{nx, now.step + 1});
		}
	}
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			diff[i] = a[i] - a[i - 1];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				bfs(j);
				if (dp[i] == 2) {
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0; 
}
