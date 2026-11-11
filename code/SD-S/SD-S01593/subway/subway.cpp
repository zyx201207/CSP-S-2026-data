#include <bits/stdc++.h>
#include <vector>
using namespace std;
const int N = 510;
const int M = 5e5 + 10;
int c, n, m, d, q;
int w[M], k[N];
vector<int> a[N], t[N];

const int MM = 1024;
long long dis[MM][MM];
void Floyd()
{
	for (int k = 1; k <= m; k++)
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= m; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	return ;
}
void sub1()
{
	for (int i = 1; i <= m; i++) 
		for (int j = 1; j <= m; j++)
			dis[i][j] = 1e18;
	for (int i = 1; i <= n; i++) 
		for (int p = 1; p <= k[i]; p++) 
			for (int q = 1; q <= k[i]; q++) 
				dis[a[i][p]][a[i][q]] = min(dis[a[i][p]][a[i][q]], 1LL * t[i][p] + 1LL * t[i][q]);
	Floyd();
	while (q--) {
		int x, y;
		scanf("%d%d", &x, &y);
		long long ans = w[x] + w[y] + dis[x][y];
		printf("%lld\n", ans);
	}
	return ;
}

#include <queue>
long long jv[MM][MM];
bool bo[MM];
struct dui{
	int x;
	long long d;
};
bool operator < (const dui &pp, const dui &qq) { return pp.d > qq.d; }
priority_queue<dui> dl;
vector<int> to[MM];
void dijkstra(int s)
{
	fill(bo + 1, bo + m + 1, 0);
	dl.push(dui{s, 0}), dis[s][s] = 0;
	while (!dl.empty()) {
		dui tou = dl.top();	dl.pop();
		int x = tou.x;
		if(bo[x])	continue;
		bo[x] = 1;
		for (int y : to[x]) {
			if(dis[s][y] > dis[s][x] + jv[x][y]) {
				dis[s][y] = dis[s][x] + jv[x][y];
				if(!bo[y])	dl.push(dui{y, dis[s][y]});
			}
		}
	}
	return ;
}
void sub2()
{
	for (int i = 1; i <= m; i++) 
		for (int j = 1; j <= m; j++)
			jv[i][j] = 1e18, dis[i][j] = 1e18;
	for (int i = 1; i <= n; i++) 
		for (int p = 1; p <= k[i]; p++) 
			for (int q = 1; q <= k[i]; q++) 
				jv[a[i][p]][a[i][q]] = min(jv[a[i][p]][a[i][q]], 1LL * t[i][p] + 1LL * t[i][q]);
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= m; j++)
			if(jv[i][j] != 1e18)
				to[i].push_back(j), to[j].push_back(i);
	for (int i = 1; i <= m; i++)	dijkstra(i);
	while (q--) {
		int x, y;
		scanf("%d%d", &x, &y);
		long long ans = w[x] + w[y] + dis[x][y];
		printf("%lld\n", ans);
	}
	return ;
}

long long co[M][3];
void sub3()
{
	for (int i = 1; i <= m; i++)	co[i][1] = co[i][2] = 1e18;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= k[i]; j++)
			co[a[i][j]][i] = t[i][j];
	if(n == 1) {
		while (q--) {
			int x, y;
			scanf("%d%d", &x, &y);
			long long ans = w[x] + w[y] + co[x][1] + co[y][1];
			printf("%lld\n", ans);
		}
	}
	else {
		long long Min = 5e18;
		for (int i = 1; i <= n; i++)	Min = min(Min, co[i][1] + co[i][2]);
		while (q--) {
			int x, y;
			scanf("%d%d", &x, &y);
			long long ans = min(min(co[x][1] + co[y][1], co[x][2] + co[y][2]), min(co[x][1] + co[y][2], co[x][2] + co[y][1]) + Min);
			ans += (w[x] + w[y]);
			printf("%lld\n", ans);
		}
	}
	return ;
}
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
//	freopen("subway4.in", "r", stdin);
//	freopen("subway4.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++)	scanf("%d", &w[i]);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &k[i]);
		a[i].resize(k[i] + 1), t[i].resize(k[i] + 1);
		for (int j = 1; j <= k[i]; j++) 	scanf("%d%d", &a[i][j], &t[i][j]);
	}
	if((1 <= c) && (c <= 6))		sub1();
	else if((7 <= c) && (c <= 11))	sub2();
	else if((20 <= c) && (c <= 21))	sub3();
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

32
17

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

35
16

20 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

32
17
*/
