#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 50;
const int M = 1e5 + 50;
int c, t, n;
ll d, a[N], dis[N], cnt[N], ans;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		ans = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		for (int i = 1; i <= n; ++i) {
			memset(dis, 0x3f, sizeof dis);
			for (int j = 1; j <= n; ++j)
				cnt[j] = 1;
			queue<int> q;
			q.push(i);
			dis[i] = 0;
			while (!q.empty()) {
				int now = q.front();
				q.pop();
				for (int j = now + 1; a[j] - a[now] <= d && j <= n; ++j) {
					if (dis[j] == dis[now] + 1) {
						cnt[j]++;
					}
					if (dis[j] > dis[now] + 1) {
						dis[j] = dis[now] + 1;
						q.push(j);
						cnt[j] = 1;
					}
				}
			}
			for (int j = i + 1; j <= n; ++j) {
				if (cnt[j] == 2) {
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}