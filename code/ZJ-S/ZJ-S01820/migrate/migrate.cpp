#include <bits/stdc++.h>
using namespace std;
int c, t, n;
long long d, ans, a[2000010];
struct node {
	int k, cnt;
};
queue<node> q;
bool bfs(int x, int y) {
	q.push({x, 0});
	int minn = 0, cnt = 0;
	while (!q.empty()) {
		node& cur = q.front();
		q.pop();
		if (cur.k == y) {
			if (minn == 0) minn = cur.cnt, cnt = 1;
			else if (cur.cnt == minn) cnt++;
			else break;
			if (cnt > 2) return false;
		}
		for (int i = cur.k + 1; i <= y; i++)
			if (a[i] - a[cur.k] <= d) q.push({i, cur.cnt + 1});
	}
	return (cnt == 2);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		ans = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> a[i];
		if (n > 5000) {
			if (d >= ((a[2] - a[1]) << 1ll) && d < (3 * (a[2] - a[1])))
				cout << n - 2 << '\n';
			else cout << "0\n";
			continue;
		}
		for (int i = 1; i < n; i++)
			for (int j = i + 1; j <= n; j++)
				ans += bfs(i, j);
		cout << ans << '\n';
	}
	return 0;
}