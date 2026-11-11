#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 505,M = 5e5 + 5;
int ct,n,m,d,q,w[M],dis[N][N];
vector<pair<int,int>> g[M];
int read()
{
	int x = 0; char c = ' ';
	while (!isdigit(c)) c = getchar_unlocked();
	while (isdigit(c)) x = x * 10 + c - '0',c = getchar_unlocked();
	return x;
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ct = read(); n = read(); m = read(); d = read(); q = read();
	for (int i = 1; i <= m; i++) w[i] = read();
	for (int i = 1; i <= n; i++)
	{
		int k;
		k = read();
		for (int j = 1; j <= k; j++)
		{
			int id,t;
			id = read(); t = read();
			g[id].push_back({i,t});
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for (int i = 1; i <= n; i++) dis[i][i] = 0;
	for (int i = 1; i <= m; i++)
		for (auto j:g[i])
			for (auto k:g[i])
				if (dis[j.first][k.first] > j.second + k.second)
					dis[j.first][k.first] = j.second + k.second;
	for (int i = 1; i <= n; i++)
		for (int k = 1; k <= n; k++)
			for (int j = 1; j <= n; j++)
				if (dis[i][j] > dis[i][k] + dis[k][j])
					dis[i][j] = dis[i][k] + dis[k][j];
	while (q--)
	{
		int x,y,ans = 1e18;
		x = read(); y = read();
		for (auto i:g[x])
			for (auto j:g[y])
				ans = min(ans,w[x] + w[y] + dis[i.first][j.first] + i.second + j.second);
		printf("%lld\n",ans);
	}
	return 0;
}