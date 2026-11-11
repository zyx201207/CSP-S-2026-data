#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 5010;
int n,d;
int x[N],dis[N][N];
bool vis[N];
long long cnt[N][N];
vector<int> e[N];
queue<int> q;

signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int c,_;cin >> c >> _;
	while (_ --) {
		cin >> n >> d;
		for (int i = 1;i <= n;i ++) cin >> x[i];
		for (int i = 1;i < n;i ++) {
			for (int j = i+1;j <= n;j ++) {
				if (x[j]-x[i] <= d) {
					e[i].push_back(j);
					e[j].push_back(i);
				}
			}
		}
		for (int i = 1;i <= n;i ++) {
			for (int j = 1;j <= n;j ++) dis[i][j] = n+1,cnt[i][j] = 0,vis[j] = 0;
			dis[i][i] = 0,cnt[i][i] = 1;q.push(i);
			while (!q.empty()) {
				int u = q.front();q.pop();
				if (vis[u]) continue;
				for (auto v : e[u]) {
					if (dis[i][v] > dis[i][u]+1) {
						dis[i][v] = dis[i][u]+1;
						cnt[i][v] = cnt[i][u];
						q.push(v);
					}
					else if (dis[i][v] == dis[i][u]+1) 
						cnt[i][v] += cnt[i][u];
				}
			}
		}
		int ans = 0;
		for (int i = 1;i < n;i ++) {
			for (int j = i+1;j <= n;j ++) {
				if (cnt[i][j] == 2) ans ++;
			}
		}
		cout << ans << '\n';
		for (int i = 1;i <= n;i ++) e[i].clear();
	}
	return 0;
}

