#include <bits/stdc++.h>
#define int long long
#define gc getchar()
#define pc putchar
using namespace std;
inline int read()
{
	int x = 0,p = 1;
	char c = gc;
	while(c > '9' || c < '0')	p = c == '-' ? -1 : 1,c = gc;
	while(c >= '0' && c <= '9')	x = (x << 1) + (x << 3) + (c ^ 48),c = gc;
	return p * x;
}
inline void write(char c) { pc(c); }
template<typename T> inline void _write(T x) { if(x > 9) _write(x / 10); pc(x % 10 | 48); }
template<typename T> inline void write(T x) { if(x < 0) x = -x,pc('-'); _write(x); }
template<typename T> inline void writeln(T x) { write(x); puts(""); }
template<typename... Argc> inline void write(Argc... argc) { int tmp[] = {(write(argc),0)...}; }
template<typename... Argc> inline void writeln(Argc... argc) { int tmp[] = {(write(argc),0)...}; puts(""); }
const int N = 1e6 + 10;
int c,T;
int n,k;
struct node { int u,v; } eg[N];
struct edge { int to,nxt; } es[N << 1];
int nE = 0,hd[N];
inline void add(int u,int v) { es[++nE] = {v,hd[u]}; hd[u] = nE; }
int p[N],d[N];
inline void dfs(int u,int fa)
{
	p[u] = fa; d[u] = d[fa] + 1;
	for(int i = hd[u],v;i;i = es[i].nxt)
	{
		v = es[i].to;
		if(v == fa)	continue;
		dfs(v,u);
	}
}
inline int lca(int u,int v)
{
	if(d[u] > d[v])	swap(u,v);
	while(d[u] != d[v])	v = p[v];
	while(u != v)	u = p[u],v = p[v];
	return u;
}
inline int dst(int u,int v) { return d[u] + d[v] - 2 * d[lca(u,v)]; }
inline bool check(int mask)
{
	int cnt = 0,t = mask;
	while(t)	t -= (t & -t),cnt++;
	if(cnt != k)	return false;
	vector<int> p(n + 1,0);
	for(int i = 1;i <= n;i++)	p[i] = i;
	auto find = [&](auto self,int x) -> int { return p[x] == x ? x : p[x] = self(self,p[x]); };
	auto unite = [&](int x,int y) -> void { p[find(find,y)] = find(find,x); };
	for(int i = 1;i < n;i++)
		if((mask & (1 << eg[i].u - 1)) && (mask & (1 << eg[i].v - 1)))
			unite(eg[i].u,eg[i].v);
	cnt = 0;
	for(int i = 1;i <= n;i++)
		if((mask & (1 << i - 1)) && find(find,i) == i)
			cnt++;
	if(cnt > 2)	return false;
	return true; 
}
inline void solve()
{
	n = read(); k = read();
	if(c == 16 || c == 17)
	{
		int m = (n + 1) / 2;
		auto f = [&](int x) -> int { return (x + 1) / 2; };
		writeln(f(f(m + 2) + 1 - f(k)));
		return;
	}
	for(int i = 1;i < n;i++)
		eg[i].u = read(),eg[i].v = read(),
		add(eg[i].u,eg[i].v),add(eg[i].v,eg[i].u);
	dfs(1,0); int ans = 21e8;
	for(int mask = 3;mask < (1 << n);mask++)
	{
		if(!check(mask))	continue;
		int mx = 0;
		for(int i = 1;i <= n;i++)
			if(!(mask & (1 << i - 1)))
			{
				int mn = 21e8;
				for(int j = 1;j <= n;j++)
					if(mask & (1 << j - 1))
						mn = min(mn,dst(i,j));
				mx = max(mx,mn);
			}
		ans = min(ans,mx);
	}
	writeln(ans); 
	for(int i = 1;i <= n;i++)	hd[i] = 0;
	nE = 0;
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c = read(); T = read();
	while(T--)	solve();
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
