#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],kk[505],A,T,st[500005][500],x,y;
long long dp[500005][500005];
//struct station{
//	int a;
//	int t;
//} st[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway,out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++)
		cin >> w[i];
	for(int i = 1;i <= n;i++)
	{
		cin >> kk[i];
		for(int j = 1;j <= kk[i];j++)
		{
			cin >> A >> T;
			st[A][i] = T;
		}
	}
	for(int i = 1;i <= m;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			for(int k = 1;k <= d;k++)
			{
				if (st[i][k] == 0)
					continue;
				for(int l = 1;l <= kk[k];l++)
				{
					if (dp[i][j] > 0)
						dp[i][j] = min(dp[i][j],dp[l][j] + st[i][k] + st[l][k]);
					else
						dp[i][j] = dp[l][j] + st[i][k] + st[l][k];
				}
			}
		}
	}
	while(q--)
	{
		cin >> x >> y;
		long long t = w[x] + w[y];
		cout << t + dp[x][y] << endl;
	}
	return 0;
}
