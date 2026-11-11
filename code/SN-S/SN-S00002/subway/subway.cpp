#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[51],k[500010],a[51][500010],t[510][50010],x,y;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	if(m==1)
	{
		cout << 0;
	}
	for(int i = 1;i<=m;i++)
	{
		cin >> w[i];
	}
	for(int i = 1;i<=n;i++)
	{
		cin >> k[i];
		for(int j = 1;j<=k[i];j++)
		{
			cin >> a[i][j] >> t[i][j];
		}
	}
	int mx=INT_MAX,my=INT_MAX;
	for(int sg = 1;sg<=q;sg++)
	{
		cin >> x >> y;
		for(int i = 1;i<=n;i++)
		{
			for(int j = 1;i<=k[i];j++)
			{
				if(a[i][j]==x)
				{
					mx=min(mx,t[i][j]);
				}
				if(a[i][j]==y)
				{
					my=min(my,t[i][j]);
				}
			}
		}
	}
	cout << (mx+my)*2;
	return 0;
} 
