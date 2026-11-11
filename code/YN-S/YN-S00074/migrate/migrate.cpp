#include <bits/stdc++.h>
using namespace std;
int c, T;
long long n, d, a[5010], vis[5010], minn[5010];

void BFS(int x) {
	queue<int> q;
	q.push(x);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = now + 1; i <= n; i++) {
			if (a[i] - a[now] <= d) {
				//cout << i << " " << now << " " << a[i] - a[now] << "UUUUUU\n";
				if (!vis[i]) {
					q.push(i);
					vis[i] += vis[now];
					minn[i] = minn[now] + 1;
				} else {
					if (minn[now] + 1 == minn[i])
						vis[i] += vis[now];
				}
			} else
				break;
		}
	}
}

void solve() {
	if (c <= 10) {
		long long ans = 0;
		for (int i = 1; i <= n; i++) {
			a[i] = 0;
		}
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				vis[j] = 0;
				minn[j] = 0;
			}
			vis[i] = 1;
			BFS(i);
			for (int j = 1; j <= n; j++) {
				//cout << vis[j] << "R" << minn[j] << "\n";
				if (vis[j] == 2)
					ans++;
			}
			//cout << i << "T\n";
		}
		cout << ans << "\n";
	}
	return;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c >> T;
	while (T--)
		solve();
	return 0;
}
//还好严格递增BFS方便点
//又来多测啊