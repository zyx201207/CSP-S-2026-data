#include <bits/stdc++.h>
#define MAXM (500050)
#define MAXN (520)
using namespace std;
int C, N, M, D, Q;
long long W[MAXM];
const long long INF = 1e15;
struct Edge {
	int to;
	long long t;
};
vector <Edge> E[MAXM];
long long G[MAXN][MAXN];
void Build() {
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=N;j++) {
			if(i == j) G[i][j] = 0;
			else G[i][j] = INF;
		}
	}
	for(int k=1;k<=M;k++) {
		for(unsigned i=0;i<E[k].size();i++) {
			int u = E[k][i].to;
			long long w1 = E[k][i].t;
			for(unsigned j=i+1;j<E[k].size();j++) {
				int v = E[k][j].to;
				long long w2 = E[k][j].t;
				//printf("%d--%d %lld\n", u, v, w1+w2); 
				G[u][v] = G[v][u] = min(G[u][v], w1+w2);
			}
		}
	}
}
void Floyd() {
	for(int k=1;k<=N;k++) {
		for(int i=1;i<=N;i++) {
			for(int j=1;j<=N;j++) {
				G[i][j] = min(G[i][j], G[i][k]+G[k][j]);
			}
		}
	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &C, &N, &M, &D, &Q);
	for(int i=1;i<=M;i++) {
		scanf("%lld", &W[i]);
	}
	for(int i=1;i<=N;i++) {
		int k, a;
		long long t;
		scanf("%d", &k);
		for(int j=1;j<=k;j++) {
			scanf("%d%lld", &a, &t);
			E[a].push_back({i, t});
		}
	}
	Build();
	Floyd();
	while(Q --) {
		int x, y;
		scanf("%d%d", &x, &y);
		long long ans = INF;
		for(unsigned i=0;i<E[x].size();i++) {
			int u = E[x][i].to;
			for(unsigned j=0;j<E[y].size();j++) {
				int v = E[y][j].to;
				ans = min(ans, W[x]+W[y]+E[x][i].t+E[y][j].t+G[u][v]);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
