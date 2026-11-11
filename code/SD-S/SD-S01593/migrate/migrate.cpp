#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
const int N = 2e6 + 10;
const int NN = 5010;
int c, T, n;
long long d, x[N], dis[NN][NN], f[NN][NN];
int to[N][2];
bool bo[NN];
vector<int> vec[NN];
queue<int> dl;

void bfs(int s)
{
	fill(bo + 1, bo + n + 1, 0);
	dl.push(s), dis[s][s] = 0, f[s][s] = 1, bo[s] = 1;
	while (!dl.empty()) {
		int x = dl.front();	dl.pop();
		for (int y : vec[x]) {
			if(bo[y])	continue;
			if(dis[s][y] > dis[s][x] + 1) {
				dis[s][y] = dis[s][x] + 1, f[s][y] = f[s][x];
				dl.push(y), bo[y] = 1;
			}
			else if(dis[s][y] == dis[s][x] + 1) 	f[s][y] += f[s][x];
		}
	}
	return ;
}
void sub1()
{
	for (int i = 1, j = 1; i <= n; i++) {
		while ((j <= n) && (x[j] - x[i] <= d))	j++;
		to[i][0] = j - 1;
	}
	for (int i = n, j = n; i >= 1; i--) {
		while ((j >= 1) && (x[i] - x[j] <= d))	j--;
		to[i][1] = j + 1;
	}
	while (T--) {
		scanf("%d%lld", &n, &d);
		for (int i = 1; i <= n; i++)	scanf("%lld", &x[i]), vec[i].clear();
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				if((j != i) && (abs(x[i] - x[j]) <= d))
					vec[i].push_back(j), vec[j].push_back(i);
				dis[i][j] = 1e18, f[i][j] = 0;
			}
		for (int i = 1; i <= n; i++)	bfs(i);
//		for (int i = 1; i <= n; i++)
//			for (int j = 1; j <= n; j++)
//				cout << i << ' ' << j << ':' << dis[i][j] << ' ' << f[i][j] << '\n';
		long long ans = 0;
		for (int u = 1; u <= n; u++)
			for (int v = u + 1; v <= n; v++)
				if(f[u][v] == 2)
					ans++;
		printf("%lld\n", ans);
	}
	return ;
}

void sub2()
{
	while (T--) {
		scanf("%d%lld", &n, &d);
		for (int i = 1; i <= n; i++)	scanf("%lld", &x[i]);
		long long ans = 0;
		for (int u = 1; u <= n; u++) {
			for (int v = u + 1; v <= n; v++) {
				if((abs(x[u] - x[v]) <= d) || (abs(x[u] - x[v]) > d * 2))	continue;
				int p = lower_bound(x + u, x + v + 1, x[v] - d) - x;
				int q = upper_bound(x + u, x + v + 1, x[u] + d) - x - 1;
				if(p + 1 == q)	ans++;
			}
		}
		printf("%lld\n", ans);
	}	
	return ;
}
void sub3()
{
	while (T--) {
		long long Min = 1e18 + 7, Max = -1e18 - 7, ans = 0;
		scanf("%d%lld", &n, &d);
		for (int i = 1; i <= n; i++)	scanf("%lld", &x[i]), Min = min(Min, x[i]), Max = max(Max, x[i]);
		if(Max - Min <= d) 	printf("0\n");
		else {
			int pos = 1;
			for (int i = 1; i <= n; i++) 
				if((x[i] - Min <= d) && (Max - x[i] <= d)) 
					pos = i;
			for (int i = 1, j = 1; i <= n; i++) {
				while ((j <= n) && (x[j] - x[i] <= d))	j++;
				to[i][0] = j - 1;
			}
			for (int i = n, j = n; i >= 1; i--) {
				while ((j >= 1) && (x[i] - x[j] <= d))	j--;
				to[i][1] = j + 1;
			}
			int cnt1 = 0, cnt2 = 0;
			for (int i = pos + 1; i <= n; i++) {
				if(to[i][1] == pos)				cnt1++;
				else if(to[i][1] == pos - 1)	cnt2++;
			}
			for (int i = 1; i < n; i++) {
				if(to[i][0] == pos)				ans += cnt2;
				else if(to[i][1] == pos + 1)	ans += cnt1;
			}
			printf("%lld\n", ans);
		}
	}
	return ;
}
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
//	freopen("migrate3.in", "r", stdin);
//	freopen("migrate3.out", "w", stdout);
	scanf("%d%d", &c, &T);
	if(c <= 6)						sub1();
	else if((7 <= c) && (c <= 10))	sub2();
	else if((13 <= c) && (c <= 14))	sub3();
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

1
2

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0
1

13 1
4 2
1 2 3 4

1
*/
