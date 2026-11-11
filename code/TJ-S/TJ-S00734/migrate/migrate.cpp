#include<bits/stdc++.h>
using namespace std;
#define ll long long

int c, T, n; 
ll d, x[2000005], dist[2000005][2];
bool b[2000005];
int q[2000005], front, rear;
vector<int> edges[2000005];

ll check(int x, int y) {
	for (int i = 1; i <= n; i++) {
		dist[i][0] = 1 << 30;
		dist[i][1] = 0;
		b[i] = false;
	}
	front = 1;
	rear = 0;
	q[++rear] = x;
	dist[x][0] = 0;
	dist[x][1] = 1;
	b[x] = true;
	while (front <= rear) {
		int u = q[front++];
		for (auto v : edges[u]) {
			if (!b[v]) {
				dist[v][0] = dist[u][0] + 1;
				dist[v][1] = dist[u][1];
				b[v] = true;
				q[++rear] = v;
			} else if (dist[v][0] == dist[u][0] + 1) {
				dist[v][1] += dist[u][1];
			}
		}
		if (u == y)
			break;
	}
	return dist[y][1];
} 

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &T);
	while (T--) {
		scanf("%d%lld", &n, &d);
		for (int i = 1; i <= n; i++) 
			scanf("%lld", &x[i]);
		for (int i = 1; i <= n; i++)
			edges[i].clear();
		for (int i = 1; i <= n; i++) 
			for (int j = i + 1; j <= n; j++) if (j != i) {
				if (abs(x[i] - x[j]) <= d) {
					edges[i].push_back(j);
					edges[j].push_back(i);
				}
			}
			/*
	for (int i = 1; i <= n; i++) {
		printf("%d :", i);
		for (auto j : edges[i])
			printf("%d ", j);
		printf("\n");
	}
	*/ 
		ll ans = 0;
		for (int i = 1; i <= n; i++) 
			for (int j = i + 1; j <= n; j++) {
				//printf("check(%d, %d) == %lld\n", i, j, check(i, j));
				if (check(i, j) == 2) {
					ans++;
				}
			}
		printf("%lld\n", ans);
	}
    return 0;
}
