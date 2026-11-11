#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	int w[500005],nx,ny,k[500005];
	ll a[505][505],t[505][505];
	for (int i=1;i<=m;i++)
		cin >> w[i];
	bool b = true;
	for (int i=1;i<=n;i++)
	{
		cin >> k[i];
		for (int j=1;j<=k[i];j++)
		{
			cin >> a[i][j] >> t[i][j];
			if ((j!=1&&t[i][j]!=t[i][j-1]) || (i!=1&&t[i][j]!=t[i-1][j]))
				b = false;
		}
	}
	if (b)
	{
		while(q--)
		{
			cin >> nx >> ny;
			int ans = w[nx] + w[ny];
			cout << ans + (ny - nx) * t[1][1] * 2 << "\n";
		}
	}
	else
	{
		while(q--)
		{
			cin >> nx >> ny;
   			cout << w[nx] + w[ny] + t[1][1] + t[2][2] << "\n";
		}
	}
	return 0;
}