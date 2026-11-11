#include<bits/stdc++.h>
using namespace std;
int a[20010][20010];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,k;
	cin >> c >> n >>m >> d >> q;
	int w[m+10];
	for(int i = 1;i<=m;i++)
	{
		cin>>w[i];
	}
	int b[m+10]={},t[m+10]={};
	for(int i = 1;i <= n;i++)
	{
		cin>>k;
		for(int j = 1;j<=k;j++)
		{
			cin >> b[j] >> t[j];
			for(int l = 1;l<j;l++)
			{
				if(a[b[l]][b[j]]==0)
				{
					a[b[l]][b[j]] = t[j]+t[l];
					a[b[j]][b[l]] = a[b[l]][b[j]];
				}
				else
				{
					a[b[l]][b[j]] = min(a[b[l]][b[j]],t[j]+t[l]);
					a[b[j]][b[l]] = a[b[l]][b[j]];
				}
			}
		}
	}
	for(int i = 1;i <= m;i++)
		{
			for(int j = 1;j<=m;j++)
			{
				if(i!=j)
				{
					for(int l = 1;l <= m;l++)
					{
						if(l!=i&&l!=j)
						{
							if(a[i][l]&&a[l][j])
							{
								if(a[i][j])
								{
									a[i][j] = min(a[i][j],a[i][l]+a[l][j]);
								}
								else
								{
									a[i][j] = a[i][l]+a[l][j];
								}
								a[j][i] = a[i][j];
							}
						}
					}
				}
			}
		}
	int x,y;
	for(int i = 1;i <= q;i++)
	{
		cin >> x >> y;
		cout<<a[x][y]+w[x]+w[y]<<endl;
	}
	return 0;
}
