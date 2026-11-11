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
#define pii pair<int,int>
const int N = 5e5 + 10; 
int c,n,m,d,q,w[N],k[N];
vector<pii> v[N];
int g[510][510];
inline void add(int u,int v,int w) { g[u][v] = g[v][u] = min(g[u][v],w); }
inline void floyd()
{
	for(int i = 1;i <= n;i++)
		for(int k = 1;k <= n;k++)
			for(int j = 1;j <= n;j++)
				g[i][k] = min(g[i][k],g[i][j] + g[j][k]);
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(g,0x3f,sizeof(g));
	c = read(); n = read(); m = read(); d = read(); q = read();
	for(int i = 1;i <= m;i++)	w[i] = read();
	for(int i = 1;i <= n;i++)
	{
		k[i] = read();
		for(int j = 1;j <= k[i];j++)
		{
			int a = read(),t = read();
			v[a].push_back({i,t});
		}
	}
	for(int i = 1;i <= m;i++)
	{
		for(int i1 = 0;i1 < v[i].size();i1++)	add(v[i][i1].first,v[i][i1].first,0);
		for(int i1 = 0;i1 < v[i].size();i1++)
			for(int i2 = i1 + 1;i2 < v[i].size();i2++)
				add(v[i][i1].first,v[i][i2].first,v[i][i1].second + v[i][i2].second);
	}
	floyd();
	while(q--)
	{
		int x = read(),y = read();
		int ans = 9e18;
		for(int i1 = 0;i1 < v[x].size();i1++)
			for(int i2 = 0;i2 < v[y].size();i2++)
				ans = min(ans,g[v[x][i1].first][v[y][i2].first] + v[x][i1].second + v[y][i2].second);
		ans += w[x] + w[y];
		writeln(ans);
	}
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

*/

