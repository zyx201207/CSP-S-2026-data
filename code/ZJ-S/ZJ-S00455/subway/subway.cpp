#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#define int unsigned
using namespace std;

char *p1,*p2,in[1000000];
#define gc() ((p1 == p2 && (p2 = (p1 = in) + fread(in,1,10,stdin),p1 == p2)) ? EOF : *p1++)

int read()
{
	int x = 0;
	char c = gc();
	while (c < 48 || c > 57) c = gc();
	while (c >= 48 && c <= 57) x = x * 10 + c - 48,c = gc();
	return x;
}

void write(unsigned long long x)
{
	if (x / 10) write(x / 10);
	putchar(x % 10 + 48);
	return;
}

int C,n,m,d,q,k,x,y,w[500010];
vector <pair <int,int>> g[500010];
unsigned long long ans,f[510][510];

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	C = read(),n = read(),m = read(),d = read(),q = read();
	for (int i = 1;i <= m;i++) w[i] = read();
	for (int i = 1;i <= n;i++) for (int j = 1;j <= n;j++) if (i != j) f[i][j] = 1e18;
	for (int i = 1;i <= n;i++)
	{
		k = read();
		while (k--)
		{
			x = read(),y = read();
			for (pair <int,int> p : g[x]) f[p.first][i] = min(f[p.first][i],(unsigned long long)(p.second + y)),f[i][p.first] = min(f[i][p.first],(unsigned long long)(p.second + y));
			g[x].push_back(make_pair(i,y));
		}
	}
	for (k = 1;k <= n;k++) for (int i = 1;i <= n;i++) for (int j = 1;j <= n;j++) f[i][j] = min(f[i][j],f[i][k] + f[k][j]);
	while (q--)
	{
		x = read(),y = read(),ans = 1e18;
		for (pair <int,int> px : g[x]) for (pair <int,int> py : g[y]) ans = min(ans,px.second + f[px.first][py.first] + py.second);
		write(w[x] + ans + w[y]),putchar('\n');
	}
	return 0;
}
