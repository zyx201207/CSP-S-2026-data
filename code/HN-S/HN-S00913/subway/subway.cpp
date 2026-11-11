#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
int c, n, m, d, q;
int k, x, y;
long long ans;
long long w[MAXN];
long long dis[505][505];//从第i条线路的站台到第j条线路的任意一个站台所需时间 
//vector<int> c[MAXN], t[MAXN];
int cnt[MAXN];//经过第i个地铁站的线路数量 
int a[MAXN][23];//经过第i个地铁站的线路编号 
long long b[MAXN][23];//经过第i个地铁站 
vector<int> e[505];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++)
	{
		cin >> w[i];
	}
	for(int i = 1; i <= n; i ++)
	{
		cin >> k;
		for(int j = 1; j <= k; j ++)
		{
			cin >> x >> y;
			cnt[x] ++;
			a[x][cnt[x]] = i;
			b[x][cnt[x]] = y;
		}
	}
	memset(dis, 0x3f, sizeof(dis));
	for(int i = 1; i <= n; i ++)
	{
		dis[i][i] = 0;
	}
	for(int i = 1; i <= m; i ++)
	{
		for(int j = 1; j <= cnt[i]; j ++)
		{
			for(int k = 1; k <= cnt[i]; k ++)
			{
				if(j == k) continue;
				dis[a[i][j]][a[i][k]] = min(dis[a[i][j]][a[i][k]], b[i][j] + b[i][k]);
			}
		}
	}
	for(int i = 1; i <= n; i ++)
	{
		for(int j = 1; j <= n; j ++)
		{
			for(int k = 1; k <= n; k ++)
			{
				dis[i][k] = min(dis[i][k], dis[i][j] + dis[j][k]);
			}
		}
	}
	while(q --)
	{
		cin >> x >> y;
		ans = (long long)(1e18);
		for(int i = 1; i <= cnt[x]; i ++)
		{
			for(int j = 1; j <= cnt[y]; j ++)
			{
				ans = min(ans, dis[a[x][i]][a[y][j]] + b[x][i] + b[y][j]);
			}
		}
		cout << w[x] + w[y] + ans << endl;
	}
	return 0;
}
