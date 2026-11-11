#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ll long long
#define IX INT_MAX

const int N = 5e5 + 5;
int c , T , n , k , fa[N] , dist[N];
vector <int> edges[N];
queue <int> q;
bool vis[N] , vis2[N];

inline void dfs(int u , int fa) {
	vis[u] = 1;
	for (auto v : edges[u]) {
		if (v == fa||!vis2[v]) continue;
		dfs(v , u);
	}
}

inline bool check(int mask) {
	for (int i = 1;i <= n;i++) vis[i] = 0;
	int cnt = 0;
	for (int i = 1;i <= n;i++) vis2[i] = 0;
	for (int i = 0;i < n;i++) if ((mask >> i) & 1) vis2[i + 1] = 1;
	for (int i = 0;i < n&&cnt < 2;i++) {
		if (((mask >> i) & 1)) {
			if (vis[i + 1]) continue;
			dfs(i + 1 , -1) , cnt++;
		}
	}
	for (int i = 0;i < n;i++) if (!vis[i + 1]&&((mask >> i) & 1)) return false;
	return true;
}

int main () {
	freopen("hub.in" , "r" , stdin);
	freopen("hub.out" , "w" , stdout);
	scanf ("%d%d" , &c , &T);
	while (T--) {
		scanf ("%d%d" , &n , &k);
		for (int i = 1;i <= n;i++) edges[i].clear();
		for (int i = 1;i < n;i++) {
			int u , v;
			scanf ("%d%d" , &u , &v);
			edges[u].push_back(v);
			edges[v].push_back(u);
		}
		if (c == 0||(1 <= c&&c <= 3)) {
			int ans = n + 1;
			for (int mask = 0;mask < (1 << n);mask++) {
				int cnt = 0;
				for (int i = 0;i < n;i++) cnt += ((mask >> i) & 1);
				if (cnt == k&&check(mask)) {
					for (int i = 1;i <= n;i++) dist[i] = n + 1;
					for (int i = 0;i < n;i++) if ((mask >> i) & 1) {
						dist[i + 1] = 0;
						q.push(i + 1);
					}
					while (!q.empty()) {
						int u = q.front();
						q.pop();
						for (auto v : edges[u]) {
							if (dist[v] > dist[u] + 1) {
								dist[v] = dist[u] + 1;
								q.push(v);
							}
						}
					}
					int cur = 0;
					for (int i = 1;i <= n;i++) cur = max(cur , dist[i]);
					ans = min(ans , cur);
				}
			}
			printf ("%d\n" , ans);
		} else cout << "You_Have_No_Egg\n";
	}
}