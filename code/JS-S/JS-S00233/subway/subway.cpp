//My dreams are made of gold
//My hearts be broken and I'm down along the road
#include <bits/stdc++.h>
using namespace std;

const int N = 505,M = 5e5 + 5;

long long w[N][N];
int dis[M],cnt[M],son[M][25],tim[M][25];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++)
		cin >> dis[i];
	for (int i = 1;i <= n;i++)
	{
		int x,a,t;
		cin >> x;
		for (int j = 1;j <= x;j++)
		{
			cin >> a >> t;
			tim[a][++cnt[a]] = t;
			son[a][cnt[a]] = i;
		}
	}
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= n;j++)
			w[i][j] = 1e18;
		w[i][i] = 0;
	}
	for (int i = 1;i <= m;i++)
		for (int j = 1;j <= cnt[i];j++)
			for (int k = j + 1;k <= cnt[i];k++)
				w[son[i][k]][son[i][j]] = w[son[i][j]][son[i][k]] = min(w[son[i][j]][son[i][k]],(long long)tim[i][j] + (long long)tim[i][k]);
	for (int k = 1;k <= n;k++)
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++)
				w[i][j] = min(w[i][j],w[i][k] + w[k][j]);
	for (int i = 1;i <= q;i++)
	{
		int s,e,u,v;
		cin >> s >> e;
		long long ans = LONG_LONG_MAX,now;
		for (int j = 1;j <= cnt[s];j++)
			for (int k = 1;k <= cnt[e];k++)
			{
				u = son[s][j],v = son[e][k];
				now = (long long)dis[s] + (long long)dis[e] + (long long)tim[s][j] + (long long)tim[e][k] + w[u][v];
				ans = min(ans,now);
			}
		cout << ans << endl;
	}
	return 0;
}
