#include <bits/stdc++.h>
using namespace std;
const int M=5e5+5,Q=1e5+5;
int n,m,d,q,c,r,op,ed,xx,yy;
int w[M],k[505],t[505][M],x[Q],y[Q];
long long ans;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int a[505][M];
	cin >> c >> n >> m >> d >> q;
	for (int i=1;i<=m;i++)
	{
		cin >> w[i];
	}
	for (int i=1;i<=n;i++)
	{
		cin >> k[i];
		for (int j=1;j<=k[i];j++)
		{
			cin >> a[i][j] >> t[i][j];
		}
	}
	for (int i=1;i<=q;i++)
	{
		cin >> x[i] >> y[i];
	}
	if (n<=2)
	{
		while (q--)
		{
			xx++;
			yy++;
			for (int i=1;i<=n;i++)
			{
				if (x[xx]==a[1][i])
				{
					op=1;
				}
				if (y[yy]==a[1][i])
				{
					ed=1;
				}
			}
			if (op==0)
			{
				op=2;
			}
			if (ed==0)
			{
				ed=2;
			}
			if (op==1&&ed==1)
			{
				ans+=t[1][x[xx]];
				ans+=t[1][y[xx]];
				cout << ans << endl;
			}
			if (op==2&&ed==2)
			{
				ans+=t[2][x[xx]];
				ans+=t[2][y[xx]];
				cout << ans << endl;
			}
		}
		return 0;
	}
	return 0;
}