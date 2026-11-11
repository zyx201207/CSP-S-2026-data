//齐君豪 西安市含光中学 SN-S00442
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int C, T;
int n, K;
int mn[1000010], dist[1000010];
int b[1000010];
vector<int> edge[1000010];

void bfs(int s) {
	for(int i = 1; i <= n; i++)
		dist[i] = 0x3f3f3f3f;
	dist[s] = 0;
	queue<int> q;
	q.push(s);
	while(!q.empty()) {
		int x = q.front();
		mn[x] = min(mn[x], dist[x]);
		q.pop();
		for(auto &y : edge[x]) {
			if(dist[x] + 1 < dist[y]) {
				dist[y] = dist[x] + 1;
				mn[y] = min(mn[y], dist[y]);
				q.push(y);
			}
		}
	}
}

void bfs2(int s, int X) {
	b[s] = 1;
	queue<int> q;
	q.push(s);
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		b[x] = 1;
		for(auto &y : edge[x]) {
			if(!b[y] && ((X >> (y - 1)) & 1)) {
				b[y] = 1;
				q.push(y);
			}
		}
	}
}

void solve() {
	scanf("%d%d", &n, &K);
	int ans = 0x3f3f3f3f;
	for(int i = 1; i <= n; i++)
		edge[i].clear();
	for(int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	if(K != 2) {
		for(int i = 0; i < (1 << n); i++) {
			int sz = 0;
			for(int j = 0; j < n; j++)
				if((i >> j) & 1)
					sz++;
			if(sz != K) continue;
			int ltk = 0;
			for(int j = 1; j <= n; j++)
				b[j] = 0;
			for(int j = 0; j < n; j++)
				if((i >> j) & 1)
					if(!b[j + 1])
						ltk++, bfs2(j + 1, i);
			if(ltk > 2) continue;
			for(int j = 1; j <= n; j++)
				mn[j] = 0x3f3f3f3f, b[j] = 0;
			for(int j = 0; j < n; j++) {
				if((i >> j) & 1) {
					bfs(j + 1);
				}
			}
			int sum = 0;
			for(int j = 1; j <= n; j++)
				sum = max(sum, mn[j]);
			ans = min(ans, sum);
		}
	} else {
		for(int u = 1; u <= n; u++) {
			for(int v = u + 1; v <= n; v++) {
				for(int j = 1; j <= n; j++)
					mn[j] = 0x3f3f3f3f;
				bfs(u);
				bfs(v);
				int sum = 0;
				for(int j = 1; j <= n; j++)
					sum = max(sum, mn[j]);
				ans = min(ans, sum);
			}
		}
	}
	printf("%d\n", ans);
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%d%d", &C, &T);
	while(T--)
		solve();
	return 0;
} 
