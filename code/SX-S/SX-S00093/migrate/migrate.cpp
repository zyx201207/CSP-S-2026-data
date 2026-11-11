#include <bits/stdc++.h>
using namespace std;
const int N = 2e6+10;
long long T, c, n, d, a[N], ans;
queue<int> q;

int dfs(int x, int y) {
	int cnt = 0, minn = INT_MAX, v, w;
	q.push(x);
	q.push(0);
	while (!q.empty()) {
		v = q.front();
		q.pop();
		w = q.front();
		q.pop();
		for (int i = v + 1; i <= y; i++) {
			if (a[i] - a[v] > d)
				break;
			if (i == y) {
				if (minn == w + 1)
					cnt++;
				if (minn > w + 1) {
					minn = w + 1;
					cnt = 1;
				}
				break;
			}
			if (w + 1 > minn)
				break;
			q.push(i);
			q.push(w + 1);
		}
	}
	return cnt == 2 ? 1 : 0;
}

void solve() {
	ans = 0;
	cin >> n >> d;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n - 2; i++) {
		for (int j = i + 2; j <= n; j++) {
			ans = ans + dfs(i, j);
		}
	}
	cout << ans << "\n";
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> T;
	while (T--)
		solve();
	return 0;
}
