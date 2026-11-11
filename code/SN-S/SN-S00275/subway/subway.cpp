#include <bits/stdc++.h>
#define inf 0x7fffffff 
using namespace std;
typedef long long ll;
ll c,n,m,d,q;
ll w[500005];
struct road
{
	ll to,len;
};
vector<road> g[500505];
ll f[1005][1005];
void duanlu()
{
	for (int i = 1;i <= n + m;i++)
	{
		f[i][i] = 0;
	}
	for (int i = 1;i <= n + m;i++)
	{
		for (int j = 0;j < g[i].size();j++)
		{
			f[i][g[i][j].to] = min(f[i][g[i][j].to],g[i][j].len);
			f[g[i][j].to][i] = min(f[g[i][j].to][i],g[i][j].len);
			for (int k = 1;k <= n;k++)
			{
				f[i][k] = min(f[i][g[i][j].to] + f[i][g[i][j].to] + f[g[i][j].to][k],f[i][k]);
				f[k][i] = min(f[g[i][j].to][i] + f[g[i][j].to][i] + f[k][g[i][j].to],f[k][i]);
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	cout << inf << endl;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++)
	{
		cin >> w[i];
	}
//	cout << n << endl; 
	for (int i = 1;i <= n;i++)
	{
//		cout << i << endl;
		ll k;
		cin >> k;
		for (int j = 1;j <= k;j++)
		{
			ll a,t;
			cin >> a >> t;
			g[a].push_back(road{m + i,t});
			g[m + i].push_back(road{a,t});
		}
	}
	for (int i = 1;i <= n + m;i++)
	{
		for (int j = 1;j <= n + m;j++)
		{
			f[i][j] = inf;
		}
//		cout << endl;
	}
	duanlu();
//	for (int i = 1;i <= n + m;i++)
//	{
//		for (int j = 1;j <= n + m;j++)
//		{
//			cout << f[i][j] << " ";
//		}
//		cout << endl;
//	}
	for (int i = 1;i <= q;i++)
	{
		ll x,y;
		cin >> x >> y;
		ll t = w[x] + w[y];
		cout << t + f[x][y] << endl;
	}
	return 0;
}
