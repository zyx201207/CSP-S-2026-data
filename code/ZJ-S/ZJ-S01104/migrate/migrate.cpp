#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=2e6+5;
int c, t, n, d, ans;
ll dis[MAXN], cnt[MAXN], x[MAXN];
vector<int> f[MAXN], e[MAXN];
queue<int> q;
void init() {
	memset(dis, 127, sizeof(dis));
	memset(cnt, 0, sizeof(cnt));
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> x[i];
		for (int i = 1; i <= n; i++) f[i].clear(), e[i].clear();
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				int dis = x[j] - x[i];
				if (dis > d) break;
				f[i].push_back(j);e[i].push_back(dis);
			}
		}
		for (int i = 1; i <= n; i++) {
			init();
			q.push(i);
			dis[i] = 0;cnt[i] = 1;
			while (!q.empty()) {
				int x = q.front();
				q.pop();
//				cout << i << " " <<x << "\n";
				for (int j = 0; j < f[x].size(); j++) {
					int sx = f[x][j], sb = dis[x] + e[x][j];
					if (sb < dis[sx]) {
						dis[sx] = sb;
						cnt[sx] = 1;
						q.push(sx);
					}
					else if (sb == dis[sx]) {
						cnt[sx]++;
					}
				}
			}
			for (int j = i + 1; j <= n; j++)
				if (cnt[j] == 2) ans++;
		}
		cout << ans << "\n";
	}
	return 0;
}
