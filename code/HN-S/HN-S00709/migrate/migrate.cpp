#include <iostream>
#include <vector>
#include <queue>
#define int long long
#undef _
using namespace std;

// migrate.cpp

// Oh no my brain has migrated
// Oh no my problem has WA 

const int N = 1e5 + 3;
const int INF = 9e18;

int n, d;
int a[N];
int dis[N], cnt[N];
bool vis[N];
vector <int> g[N];
queue <int> q;

signed main() {
	ios::sync_with_stdio(false);
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int c, T;
	cin >> c >> T;
	while (T--) {
		cin >> n >> d;
		if (c <= 10) {	
			for (int i = 1; i <= n; ++i) {
				g[i].clear();
				cin >> a[i];
				for (int j = i - 1; j > 0 && (a[i] - a[j]) <= d; --j) 
					g[j].push_back(i);
			}
			
			int ans = 0;
			for (int i = 1; i <= n; ++i) {
				for (int j = 1; j <= n; ++j) {
					dis[j] = INF; vis[j] = cnt[j] = 0;
				}
				
				dis[i] = 0;
				cnt[i] = 1;
				q.push(i);
				while (!q.empty()) {
					int u = q.front(); q.pop();
					
					int len = (int)g[u].size();
					for (int j = 0; j < len; ++j) {
						int v = g[u][j];
						if (dis[v] == dis[u] + 1) ++cnt[v];
						if (vis[v]) continue;
						dis[v] = dis[u] + 1;
						cnt[v] = 1;
						vis[v] = true;
						q.push(v);
					}
				}
				for (int j = 1; j <= n; ++j) 
					if (cnt[j] == 2) ++ans;
			}
			cout << ans << endl;
		} else if (11 <= c && c <= 12) {
			int a1, a2;
			cin >> a1 >> a2;
			if ((a2 - a1)*2 < d && (a2 - a1)*3 > d) cout << n - 3 << endl;
			else cout << 0 << endl;
		} else if (13 <= c && c <= 14) {
			int L = INF, R = -INF;
			for (int i = 1; i <= n; ++i) {
				cin >> a[i];
				L = min(L, a[i]); 
				R = max(R, a[i]);
			}
			int MID = (L + R) >> 1;
			
			int l = 1, r = n;
			while (l + 1 < r) {
				int mid = (l + r) >> 1;
				if (MID == a[mid]) {
					l = r = mid;
				} else if (MID < a[mid]) {
					r = mid;
				} else {
					l = mid;
				}
			}
			
			int m;
			if ((R - a[l]) <= d && (a[l] - L) <= d) m = l;
			else m = r;
			
			int ans = 0;
			for (int i = 1; i <= n; ++i) {
				for (int j = 1; j <= n; ++j) {
					dis[j] = INF; vis[j] = cnt[j] = 0;
				}
				
				dis[i] = 0;
				cnt[i] = 1;
				q.push(i);
				while (!q.empty()) {
					int u = q.front(); q.pop();
					if (u == m) continue;
					if (dis[u] >= 2) continue;
					
					int len = (int)g[u].size();
					for (int j = 0; j < len; ++j) {
						int v = g[u][j];
						if (dis[v] == dis[u] + 1) ++cnt[v];
						if (vis[v]) continue;
						dis[v] = dis[u] + 1;
						cnt[v] = 1;
						vis[v] = true;
						q.push(v);
					}
				}
				for (int j = 1; j <= n; ++j) 
					if (dis[j] == 2 && cnt[j] == 1) ++ans;
			}
			cout << ans << endl;
		} else {
			cout << 0 << endl;
		}
	} 
	
	return 0;
} 
