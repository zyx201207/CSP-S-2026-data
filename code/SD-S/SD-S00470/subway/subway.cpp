#include <bits/stdc++.h>
using namespace std;

const int maxn = 500 , maxm = 5e5;
const long long inf = 2e18;

int c , n , m , d , q;
int w[maxm + 5];
vector<pair<int , int> > sub[maxm + 5];
long long dis[maxn + 5][maxn + 5];

int main() {
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	scanf ("%d%d%d%d%d" , &c , &n , &m , &d , &q);
	for (int i = 1; i <= m; i++)
		scanf ("%d" , &w[i]);
	for (int i = 1; i <= n; i++) {
		int k;
		scanf ("%d" , &k);
		for (int j = 1; j <= k; j++) {
			int a , t;
			scanf ("%d%d" , &a , &t);
			sub[a].push_back({i , t});
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dis[i][j] = inf;
	for (int i = 1; i <= n; i++)
		dis[i][i] = 0;
	for (int i = 1; i <= m; i++)
		for (auto p1 : sub[i]) {
			int u = p1.first , t1 = p1.second;
			for (auto p2 : sub[i]) {
				int v = p2.first , t2 = p2.second;
				dis[u][v] = min(dis[u][v] , (long long) t1 + t2);
				dis[v][u] = min(dis[v][u] , (long long) t1 + t2);
			}
		}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dis[i][j] = min(dis[i][j] , dis[i][k] + dis[k][j]);
	while (q--) {
		int u , v;
		scanf ("%d%d" , &u , &v);
		long long mi = inf;
		for (auto p1 : sub[u]) {
			int u = p1.first , t1 = p1.second;
			for (auto p2 : sub[v]) {
				int v = p2.first , t2 = p2.second;
				mi = min(mi , t1 + t2 + dis[u][v]);
			}
		}
		printf ("%lld\n" , mi + w[u] + w[v]);
	}
}
