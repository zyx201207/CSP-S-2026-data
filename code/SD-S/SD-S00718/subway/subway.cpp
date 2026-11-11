#include <bits/stdc++.h>
using namespace std;
const int Q = 100005,M = 505;
int c,d,m,n,q,x[Q],y[Q],a[M][M],t[M][M],w[M],k[M];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++)
	{
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++)
	{
		cin >> k[i];
		for(int j = 1;j <= k[i];j++)
		{
			cin >> a[i][j] >> t[i][j];
		}
	}
	for(int i = 1;i <= q;i++)
	{
		cin >> x[i] >> y[i];
	}
	for(int p = 1;p <= q;p++)
	{
		int ans = 213132100;
		for(int i = 1;i <= n;i++)
		{
			int l=212121212,r=212121212;
			for(int j = 1;j <= k[i];j++)
			{
				if(a[i][j] == x[p])
					l = t[i][j]+w[a[i][j]];
				if(a[i][j] == y[p])
					r = t[i][j]+w[a[i][j]];
			}
			ans = min(ans,l+r);
		}
		cout << ans << endl;
	}
	return 0;
}
