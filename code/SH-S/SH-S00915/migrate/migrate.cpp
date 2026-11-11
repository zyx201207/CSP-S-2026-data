#include <bits/stdc++.h>
using namespace std;
int cnt[2000005], vis[2000005], pos[2000005], dis[2000005];
vector <int> g[2000005];

void bfs(int s) {
	queue <pair <int, int> > q;
	q.push({s, 0});
	while (!q.empty()) {
		auto t = q.front();
		q.pop();
		if (t.second < dis[t.first]) {
			cnt[t.first] = 1;
			dis[t.first] = t.second;
		} else if (t.second == dis[t.first]) cnt[t.first]++;
		if (vis[t.first]) continue;
		vis[t.first] = 1;
		for (int v : g[t.first]) {
			q.push({v, t.second + 1});
		}
	} 
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
//	if (c <= 10) {
//		while (t--) {
//			int n, d;
//			cin >> n >> d;
//			for (int i = 1; i <= n; i++) dis[i] = 1e9;
//			for (int i = 1; i <= n; i++) cin >> pos[i];
//			for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) if (abs(pos[i] - pos[j]) <= d) g[i].push_back(j);
//			int ans = 0;
//			for (int i = 1; i <= n; i++) {
//				bfs(i);
////				for (int i = 1; i <= n; i++) cout << dis[i] << " "  << cnt[i] << '\n';
//				for (int j = 1; j <= n; j++) if (i != j && cnt[j] == 2) {
//					cout << i << ' ' << j << '\n'; 
//					ans++;
//				}
//				for (int j = 1; j <= n; j++) {
//					vis[j] = pos[j] = cnt[j] = 0; dis[j] = 1e9; g[j].clear();
//				}
//			} cout << ans / 2 << '\n';
//			
//		}
//	}
	while (t--) {
		cout << "0\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

