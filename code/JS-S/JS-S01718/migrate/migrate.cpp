#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e6;

int cnt[N + 5];
int a[N + 5];
int vis[N + 5];

int c, t;
int n, d;
int ans;

vector<int> g[N + 5];

bool bfs(int x, int aim) {
	memset(cnt, 0, sizeof(cnt));
	memset(vis, 0x3f3f3f3f, sizeof(vis));
	int minn = INT_MAX;
	queue<pair<int, int>> q;
	q.push({x, 0});
	while(!q.empty()) {
		int now = q.front().first;
		int step = q.front().second;
		q.pop();
		if (now == aim) {
			if (step <= minn) {
				minn = step;
				cnt[minn]++;
			}
		}
		
		if(step >= vis[now])
			continue;
		vis[now] = step;
		

		for (int v : g[now]) {
			q.push({v, step + 1});			
		}
	}
	if (minn == INT_MAX)
		return false;
	if (cnt[minn] == 2)
		return true;
	else
		return false;
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c >> t;
	for (int p = 1; p <= t; p++) {
		memset(g, 0, sizeof(g));
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}			
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++){ 
				if (a[j] - a[i] <= d) {
					g[i].push_back(j);				
				}
				else
					break;
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if(bfs(i, j) == true) {
					ans++;
				}
			}
		}
		cout << ans << '\n';
		ans = 0;
	}
}
