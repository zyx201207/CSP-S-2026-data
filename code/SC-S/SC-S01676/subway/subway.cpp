#include<bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
using pii = pair<int,int>;
const int maxn = 5e5 + 5;
int c,n,m,d,q,top;
char stk[20];
int dis[505][505];
pii vec[maxn][25];
int idx[maxn],w[maxn];
int read()
{
	int x = 0,f = 1,ch = getchar();
	while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
	while (isdigit(ch)){x = x * 10 + (ch ^ 48); ch = getchar();}
	return x * f;
}
void write(int x)
{
	top = 0;
	while (x)
	{
		stk[++top] = x % 10 + '0';
		x /= 10;
	}
	while (top)
		putchar(stk[top--]);
	putchar('\n');
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c = read(),n = read(),m = read(),d = read(),q = read();
	for (int i = 1; i <= m; i++)
		w[i] = read();
	int u,v,k,res;
	for (int i = 1; i <= n; i++)
	{
		cin >> k;
		while (k--)
		{
			u = read(),v = read();
			vec[u][++idx[u]] = {i,v};
		}
	}
	// 这里求每个地铁线路联通的最小代价
	for (int i = 1; i <= n; i++)
	{
		memset(dis[i],0x3f,sizeof(int) * (n + 5));
		dis[i][i] = 0;
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= idx[i]; j++)
		{
			for (int k = 1; k < j; k++)
			{
				u = vec[i][j].first,v = vec[i][k].first;
				dis[u][v] = dis[v][u] = min(dis[u][v],vec[i][j].second + vec[i][k].second);
			}
		}
	}// 这里是一个 5e5 * 200 = 1e8
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (dis[i][k] != inf && dis[k][j] != inf)
					dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
	int ans = 0;
	// 这里是一个 500 ^ 3 = 1.25e8
	while (q--)
	{
		cin >> u >> v,res = inf;
		for (int i = 1; i <= idx[u]; i++)
			for (int j = 1; j <= idx[v]; j++)
				res = min(res,dis[vec[u][i].first][vec[v][j].first] + vec[u][i].second + vec[v][j].second);
		write(res + w[u] + w[v]);
	}
	// 这里是一个 1e5 * 400 = 0.4e8
	// 合计 2.65e8，我相信CCF的评测机
	// tmd复健没有复健卡常技巧，这无疑是难绷的
	// 跑不过给了兄弟。CCF换机子之后更是对常数不管不顾，去年也是
	// 草拟吗输出 500MS，没复习快写板子给了呗
	// 我说这个输出 500MS 真的有点私人了
	// 但是咱学校 i3-6100 能在 1500MS 内跑完
	// 加上CCF的机子比这好一百万，应该可以吧？
	// 哎我说白了我自己的 i5-12400 都能跑的到它的两倍以内，CCF的机子不是随便跑？
	return 0;
}