#include<bits/stdc++.h>
#define int int64_t
using String = std::string;
constexpr int N = 2e6 + 5;
constexpr int inf = 0x3f3f3f3f;

int c, t, n;
int d, ans;
int x[N];
bool vis[N];
int dis[N];
int cnt[N];
std::vector<int> g[N];
std::priority_queue<std::pair<int, int>> q;

void dij(int x) {
	std::fill(vis + 1, vis + 1 + n, false);
	std::fill(dis + 1, dis + 1 + n, inf);
	std::fill(cnt + 1, cnt + 1 + n, 0);
	
	q.emplace(0, x);
	dis[x] = 0;
	cnt[x] = 1;
	while(!q.empty()) {
		int u = q.top().second; q.pop();
//		std::cout << u << ' ';
		if(vis[u]) continue;
		vis[u] = true;
		for(int v : g[u]) {
			if(dis[v] == dis[u] + 1) {
				cnt[v] += cnt[u];
			}
			else if(dis[v] > dis[u] + 1) {
				dis[v] = dis[u] + 1;
				cnt[v] = cnt[u];
				q.emplace(-dis[v], v);
			}
		}
	}
}

int32_t main() {
//	freopen("migrate\\migrate4.in", "r", stdin);
//	freopen("my.out", "w", stdout);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	std::cin.tie(nullptr) -> sync_with_stdio(false);
	std::vector<int> empty;
	
	std::cin >> c >> t;
	while(t--) {
		std::cin >> n >> d;
		
		ans = 0;
		std::fill(g + 1, g + 1 + n, empty);
		
		if(c == 11 || c == 12) {
			for(int i = 1; i <= n; i++) std::cin >> x[i];
			int D = x[2] - x[1];
//			std::cout << D << ' ' << d << ' ' << n << ' ';
			if(d < 2 * D || n - d / D * 2 + 1 <= 0) { std::cout << 0 << '\n'; }
			else { std::cout << n - d / D * 2 + 1 << '\n'; }
			continue;
		}
		
		if(c == 13 || c == 14) {
			for(int i = 1; i <= n; i++) std::cin >> x[i];
			std::cout << 0 << '\n';
			continue;
		}
		
		for(int i = 1; i <= n; i++) {
			std::cin >> x[i];
			for(int j = i - 1; j >= 1; j--) {
				if(x[i] - x[j] > d) break;
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
		
		
		for(int i = 1; i <= n; i++) {
			dij(i);
			for(int j = i + 1; j <= n; j++) {
				if(cnt[j] == 2) {
					ans++;
				}
			}
		}
		std::cout << (int64_t) ans << '\n';
	}
	
	return 0;
}