#include <bits/stdc++.h>
using namespace std;
const int N = 505,M = 20005;
int w[M],a[N][M],t[N][M],k[N];
bool vis[M];
int c,n,m,d,q,y;
long long ans;
void dfs(int lst,int x,long long s)
{
	if (x == y) ans = min(ans,s);
	if (x == y || s > ans) return;
	for (int i = 1;i <= n;i++)
	{
		if (i == lst) continue;
		bool f = 0;
		long long sum = s;
		for (int j = 1;j <= k[i];j++)
		{
			if (a[i][j] == x)
			{
				f = 1,vis[a[i][j]] = 1,sum += t[i][j];
				break;
			}
		}
		if (!f) continue;
		for (int j = 1;j <= k[i];j++)
			if (!vis[a[i][j]]) dfs(i,a[i][j],sum + t[i][j]);
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++) cin >> w[i];
	for (int i = 1;i <= n;i++)
	{
		cin >> k[i];
		for (int j = 1;j <= k[i];j++) cin >> a[i][j] >> t[i][j];
	}
	while (q--)
	{
		for (int i = 1;i <= m;i++) vis[i] = 0;
		ans = 1e18;
		int x;
		cin >> x >> y;
		dfs(-1,x,0);
		cout << ans + w[x] + w[y] << endl;
	}
	return 0;
}
// 15:16-16:08 44pts
