#include <bits/stdc++.h>

using namespace std;

#define ll long long 

namespace IO
{
#define gc getchar
#define pc putchar
	template<typename T> inline void read(T& x)
	{
		x = 0; char ch = gc(); int w = 1; 
		while (!isdigit(ch)) { if (ch == 0x2d) { w = 0; } ch = gc(); }
		while (isdigit(ch)) { x = x * 0xa + ch - 0x30; ch = gc(); }
		x = w ? x : -x; 
	}
	template<typename T> inline void write(T x)
	{
		if (x < 0) { pc(0x2d); x = -x; }
		if (x > 9) { write(x / 0xa); }
		pc(x % 0xa + 0x30);
	}
} using namespace IO;

const int N = 1e5 + 5;
int n, k, s, t; vector<int> e[N]; 

int fa[N], dis[N];
inline void dfs1(int u, int ff)
{
	dis[u] = 0;
	for (int i = 0, v; i < e[u].size(); ++i) if (e[u][i] != ff) 
	{ v = e[u][i]; dfs1(v, u); dis[u] = max(dis[u], dis[v]); }
	dis[u]+= 1; 
}
inline void dfs2(int u, int ff)
{
	fa[u] = ff; dis[u] = 0; 
	for (int i = 0, v; i < e[u].size(); ++i) if (e[u][i] != ff)
	{ v = e[u][i]; dfs2(v, u); dis[u] = max(dis[u], dis[v]);  }
	dis[u]+= 1; 
}
inline int dfs3(int u, int ff)
{
	int res = 0; 
	for (int i = 0, v; i < e[u].size(); ++i) if (e[u][i] != ff)
	{ v = e[u][i]; res = max(res, dfs3(v, u)); }
	return res + 1; 
}

int a[N], top, tag[N], f[N]; 
int pre[N], suf[N]; 

inline void work()
{
	read(n); read(k); 
	for (int i = 1, u, v; i < n; ++i) { cin >> u >> v; e[u].push_back(v); e[v].push_back(u); }
	dfs1(1, 0); s = 1; for (int i = 1; i <= n; ++i) { if (dis[i] > dis[s]) s = i; } 
	dfs2(s, 0); t = 1; for (int i = 1; i <= n; ++i) { if (dis[i] > dis[t]) t = i; }
	a[top = 1] = t; tag[t] = 1; while (t) { t = fa[t]; a[++top] = t; tag[t] = 1; }
	for (int i = 2; i < top; ++i) 
	{ for (int o = 0, v; o < e[u].size(); ++o) { v = e[u][o]; if (!tag[v]) { f[u] = max(f[u], dfs3(v, u)); } } }
//	pre[1] = 0; for (int i = 2; i <= top; ++i) {  }
	write(top / 3); putchar(0xa); 
	for (int i = 1; i <= n; ++i) { pre[i] = suf[i] = dis[i] = fa[i] = tag[i] = 0; }
}

int main()
{
	freopen("hub.in", "r", stdin); freopen("hub.out", "w", stdout); 
	int c, t; read(c); read(t); while (t--) { work(); }
	return 0; 
}
/*
w1^2r1=\frac{m1m2}{(r1+r2)^2}
w2^2r2=\frac{m1m2}{(r1+r2)^2}=w1^2r1
=> w1/w2=\sqrt(r1/r2)
*/
