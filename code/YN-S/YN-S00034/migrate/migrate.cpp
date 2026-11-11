#include <bits/stdc++.h>
using namespace std;
long long c, t, cnt, ans;
long long n, d;
long long a[2000005];
bool vis[2000005];
vector<long long>ve[2000005];

void bfs(long long x, long long y) {
	queue<long long>q;
	q.push(x);
	vis[x] = true;

	while (!q.empty()) {
		long long t = q.front();
		q.pop();

		for (auto v : ve[t]) {
			if (!vis[v]) {
				if (v == y)
					cnt++;
				q.push(v);
				vis[v] = true;
			} else if (v == y) {
				cnt++;
			}
		}
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;

	while (t--) {
		cin >> n >> d;

		for (long long i = 1; i <= n; i++) {

			cin >> a[i];
		}

		memset(ve, 0, sizeof ve);

		for (long long i = 1; i <= n; i++) {

			for (long long j = i + 1; j <= n; j++) {

				if (abs(a[i] - a[j]) <= d) {
					ve[i].push_back(j);
					ve[j].push_back(i);
				}
			}
		}


		for (long long i = 1; i <= n; i++) {


			for (long long j = i + 1; j <= n; j++) {

				cnt = 0;
				memset(vis, 0, sizeof vis);
				bfs(i, j);
				ans = 0;

				if (cnt == 2) {
					cout << i << " " << j << endl;
					ans++;
				}
			}
		}

		cout << ans << endl;
	}

	return 0;
}