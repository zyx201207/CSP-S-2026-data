#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],a[505],t[500005];
vector<long long> g[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i=1; i<=m; i++)
	{
		cin >> w[i];
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			g[i][j]=0x3f3f3f3f;
		}
		g[i][i]=0;
	}
	for (int i=1; i<=n; i++)
	{
		int k;
		cin >> k;
		for (int j=1; j<=k; j++)
		{
			cin >> a[j] >> t[j];
		}
		for (int j=1; j<=k; j++)
		{
			for (int l=j+1; j<=k; l++)
			{
				if (g[a[j]][a[l]]==0) g[a[j]][a[l]]=t[j]+t[l];
				else g[a[j]][a[l]]=min(g[a[j]][a[l]],t[i]+t[j]);
			}
		}
	}
	for (int i=1; i<=q; i++)
	{
		int x,y;
		cin >> x >> y;
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			cout << g[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}
