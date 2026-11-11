#include<bits/stdc++.h>
using namespace std;
const int N = 5e2 + 10, M = 5e5 + 10; 
typedef long long ll;
int idx, h[N], ne[M], to[M];
int w[N], sub[M];
int t[N][M];
ll ans = 0;
int x, y;
inline int read()
{
	int x = 0, c = getchar(), k = 1;
	while (c != '-' && (c < '0' || c > '9')) c = getchar(); 
	if (c == '-') k = -1, c = getchar();
	do x = x * 10 + (c ^ 48), c = getchar();
	while('0' <= c && c <= '9');
	return x * k;
}
inline void write(int x)
{
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar(x % 10 ^ 48);
}
inline void write(int x, char c)
{
	write(x), putchar(c);
}
void add(int a, int b, int c)
{
	ne[idx] = h[a];
	to[idx] = b;
	sub[idx] = c;
	h[a] = idx ++;
}
void dfs(int u, int subway, ll time, int from)
{
//	write(u, ' '), write(subway, ' '), write(time, '\n');
	if (u == y)
	{	
		time += t[subway][y];
		time += w[y];
//		write(time, '\n');
		ans = min(time, ans);
		return;
	}
	if (time >= ans) return;
	for (int i = h[u]; ~i; i = ne[i])
	{
		if (i == (from ^ 1)) continue;
		int v = to[i];
//		write(u, ' '), write(v, ' '), write(subway, ' '), write(sub[i], '\n');
		if (sub[i] != subway)
		{
			int tm = time;
			if (u != x) tm += t[subway][u];
			tm += t[sub[i]][u];
			dfs(v, sub[i], tm, i);
		}
		else
			dfs(v, subway, time, i);
	}
}
signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(h, -1, sizeof h);
	int c = read(), n = read(), m = read(), d = read(), q = read();
	for (int i = 1; i <= m; i ++)
		w[i] = read();
	memset(t, 0x3f, sizeof t);
	for (int i = 1; i <= n; i ++)
	{
		int len = read();
		int lst = 0;
		for (int j = 1; j <= len; j ++)
		{
			int sd = read();
			t[i][sd] = read();
			if (lst) add(lst, sd, i), add(sd, lst, i);
			lst = sd;
		}
	}
	while (q --)
	{
		x = read(), y = read();
		ans = 2e9;
			dfs(x, 0, w[x], -1);
		write(ans, '\n');
	}
	return 0;
}

