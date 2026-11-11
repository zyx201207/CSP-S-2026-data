#include <bits/stdc++.h>
#define ll unsigned long long
#define int unsigned int
using namespace std;

constexpr int MAXN = 505,MAXM = 5e5 + 5;
constexpr ll inf = 0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q,w[MAXM],top[MAXM];
ll f[MAXN][MAXN],rec[MAXM][25];
inline ll makePair(ll A,ll B)
{return A << 32 | B;}
inline int getFirst(ll P)
{return P >> 32;}
inline ll getSecond(ll P)
{return P & 0xffffffff;}
#define getchar getchar_unlocked
inline int read()
{
	int x = 0;
	char ch = getchar();
	while(!isdigit(ch))
		ch = getchar();
	while(isdigit(ch))
	{
		x = (x << 3) + (x << 1) + (ch ^ 48);
		ch = getchar();
	}
	return x;
}
signed main()
{
	freopen("subway.in","r",stdin),freopen("subway.out","w",stdout);
	c = read(),n = read(),m = read(),d = read(),q = read();
	for(int i = 1;i <= m;i++)
		w[i] = read();
	for(int i = 1,k,a,t;i <= n;i++)
	{
		k = read();
		for(int j = 1;j <= k;j++)
		{
			a = read(),t = read();
			rec[a][++top[a]] = makePair(i,t);
		}
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= n;j++)
			f[i][j] = inf;
		f[i][i] = 0;
	}
	for(int u = 1;u <= m;u++)
	{
		for(int i = 1;i <= top[u];i++)
		{
			for(int j = 1;j <= top[u];j++)
				f[getFirst(rec[u][i])][getFirst(rec[u][j])] = min(f[getFirst(rec[u][i])][getFirst(rec[u][j])],getSecond(rec[u][i]) + getSecond(rec[u][j]));
		}
	}
	for(int k = 1;k <= n;k++)
	{
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= n;j++)
				f[i][j] = min(f[i][j],f[i][k] + f[k][j]);
		}
	}
	int x,y;
	while(q--)
	{
		x = read(),y = read();
		ll ans = inf;
		for(int i = 1;i <= top[x];i++)
		{
			for(int j = 1;j <= top[y];j++)
				ans = min(ans,f[getFirst(rec[x][i])][getFirst(rec[y][j])] + getSecond(rec[x][i]) + getSecond(rec[y][j]));
		}
		cout << ans + w[x] + w[y] << '\n';
	}
}