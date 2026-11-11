#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int SIZE = 2e6 + 5, inf = 2e18 + 5;
int c, d, n, x[SIZE], dis[5005][5005], cnt[5005][5005];
vector <int> e[SIZE];

queue <int> q;

void bfs(int start){
	while (!q.empty()) q.pop();
	q.push(start);
	dis[start][start] = 0;
	while (!q.empty()){
		int cur = q.front();
		q.pop();
		for (int i : e[cur]){
			if (cnt[start][i]){
				if (dis[start][i] == dis[start][cur] + 1){
					cnt[start][i]++;
					q.push(i);
				}
			}	
			else {
				q.push(i);
				dis[start][i] = dis[start][cur] + 1;
				cnt[start][i] = 1;
			}
		}
	}
	return;
}

void solve1_10() {
	int ans = 0;
	cin >> n >> d;
	for (int i = 1; i <= n; i++)cin >> x[i];
	for (int i = 1; i <= n; i++)e[i].clear();
	for (int i = 0; i <= n; i++){
		for (int j = 0; j <= n; j++){
			cnt[i][j] = 0;
			dis[i][j] = inf;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (x[j] - x[i] <= d)e[i].push_back(j), e[j].push_back(i);
		}
	}
	for (int i = 1; i <= n; i++)bfs(i);
	for (int i = 1; i <= n; i++){
		for (int j = i + 1; j <= n; j++){
			if (cnt[i][j] == 2) ans++;
		}
	}
	cout << ans << "\n";
	return;
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> c >> t;
	while (t--){
		solve1_10();
	}
	return 0;
}
