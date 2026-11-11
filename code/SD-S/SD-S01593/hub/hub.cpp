#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int c, T, n, k;
int fa[N];
bool bo[N];
int ans;
int head[N], tot = 0;
struct edge{
	int nxt, to;
} l[N << 1];

void jia(int u, int v)
{
	l[tot] = edge{head[u], v}, head[u] = tot++;
	return ;
}
int cha(int x) { return (fa[x] == x) ? x : fa[x] = cha(fa[x]); }
void he(int x, int y)
{
	int gx = cha(x), gy = cha(y);
	if(gx == gy)	return ;
	fa[gx] = gy;
	return ;
}
int dfs(int x, int fa)
{
	int res = 0;
	for (int i = head[x]; i != -1; i = l[i].nxt) {
		int y = l[i].to;
		if(bo[y] || (y == fa))	continue;
		res = max(res, dfs(y, x) + 1);
	} 
	return res;
}
void sou(int p, int cnt)
{
	if((cnt > k) || (cnt + (n - p + 1) < k))	return ;
	if(p == n + 1) {
		vector<int> vec;
		for (int i = 1; i <= n; i++) {
			if(bo[i])	vec.push_back(i);
			fa[i] = i;
		}
		for (int u : vec) 
			for (int i = head[u]; i != -1; i = l[i].nxt) 
				if(bo[l[i].to])
					he(u, l[i].to);
		int cc = 0;
		for (int u : vec) {
			if(fa[u] == u) {
				cc++;
				if(cc > 2)	return ;				
			}
		}
		int res = 0;
		for (int u : vec) 	res = max(res, dfs(u, u));
		ans = min(ans, res);		
		return ;
	}
	bo[p] = 0, sou(p + 1, cnt);
	bo[p] = 1, sou(p + 1, cnt + 1);
	return ;
}
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%d%d", &c, &T);
	while (T--) {
		memset(head, -1, sizeof head), tot = 0;
		ans = 1e9;
		scanf("%d%d", &n, &k);
		for (int i = 1; i < n; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			jia(u, v), jia(v, u);
		}
		sou(1, 0);
		printf("%d\n", ans);
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

1
2
*/
