#include <bits/stdc++.h>
using namespace std;

pair<int, int>t[100005];
int n, k, dis[20005][20005];

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int c, T;
	cin >> c >> T;
	while(T --) {
		cin >> n >> k;
		memset(dis, 0x3f, sizeof(dis));
		for(int i = 1;i < n;i ++) {
			int u, v;
			cin >> u >> v;
			t[u].first ++, t[v].first ++;
			t[u].second = u, t[v].second = v;
			dis[u][v] = dis[v][u] = 1;
			dis[i][i] = 0;
		}
		dis[n][n] = 0;
		for(int k = 1;k <= n;k ++){
			for(int i = 1;i <= n;i ++) {
				for(int j = 1;j <= n;j ++) {
					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
				}
			}
		}
		sort(t + 1, t + n + 1);
		int ans = -1;
		for(int i = 1;i <= n - k;i ++) {
			int sum = 0x3f3f3f3f;
			for(int j = n - k + 1;j <= n;j ++) {
				sum = min(dis[t[i].second][t[j].second], sum);
			}
			ans = max(ans, sum);
		}
		cout << ans - 1 << '\n';
	}
	return 0;
}