#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<long long, long long> pii;
int a[2000006];
int n, d;//1-6
int dis[2000006], cnt[2000006];
void bfs(int x) {
	memset(dis, 0, sizeof dis);
	memset(cnt, 0, sizeof cnt);
	priority_queue<pii> q;
	q.push({0, x});
	while (q.size()) {
		int now = q.top().second;
		int l = q.top().first;
		q.pop();
		if (dis[now] == 0) {
			dis[now] = l;
			cnt[now] = 1;
		}
		else if (dis[now] == l) cnt[now]++;
		else continue;
		for (int i = now + 1; i <= n; i++) {
			if (a[i] - a[now] > d) break;
			q.push({l + 1, i});
		}
	}
	return;
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c, t;
	cin >> c >> t;
	if (c <= 10) {
		while (t--) {
			int ans = 0;
			cin >> n >> d;
			for (int i = 1; i <= n; i++) cin >> a[i];
			for (int i = 1; i <= n; i++) {
				bfs(i);
				for (int j = i + 1; j <= n; j++) {
					ans += (cnt[j] == 2);
				}
			}
			cout << ans << '\n';
		}
		return 0;
	}
	return 0;
}
