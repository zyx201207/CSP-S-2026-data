//齐君豪 西安市含光中学 SN-S00442
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int C, T;
int n;
ll d;
ll x[2000010];
int dist[2000010], dp[2000010];
vector<int> edge[2000010];

void bfs(int s) {
	for(int i = 1; i <= n; i++)
		dist[i] = 0x3f3f3f3f, dp[i] = 0;
	dist[s] = 0;
	dp[s] = 1;
	queue<int> q;
	q.push(s);
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		for(auto &y : edge[x]) {
			if(dist[x] + 1 < dist[y]) {
				dist[y] = dist[x] + 1;
				q.push(y);
				dp[y] = dp[x];
			} else if(dist[x] + 1 == dist[y])
				dp[y] += dp[x];
		}
	}
}

void solve() {
	int ans = 0;
	scanf("%d%lld", &n, &d);
	for(int i = 1; i <= n; i++)
		scanf("%lld", &x[i]);
	for(int i = 1; i <= n; i++)
		edge[i].clear();
	for(int i = 1; i <= n; i++)
		for(int j = i + 1; j <= n; j++) {
			if(abs(x[i] - x[j]) <= d) {
				edge[i].push_back(j);
				edge[j].push_back(i);
			}
		}
	for(int i = 1; i <= n; i++) {
		bfs(i);
		for(int j = 1; j <= n; j++)
			if(dp[j] == 2)
				ans++;
	}
	printf("%d\n", ans / 2);
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &C, &T);
	while(T--)
		solve();
	return 0;
} 
