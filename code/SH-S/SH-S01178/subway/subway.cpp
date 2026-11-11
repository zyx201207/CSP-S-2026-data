#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
bool b1[25][25];
int c1[25][25];
int a1[25][25];
int c,n,m,d,q;
int m1[20004],x[20004],y[20004];
int ans = 0x3f3f3f;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++)
	{
		cin >> m1[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin >> k;
		for(int j=1;j<=k;j++)
		{
			cin >> c1[i][j] >> a1[i][j];
			b1[i][j] = 1;
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin >> x[i] >> y[i];
		for(int j=1;j<=m;j++)
		{
			if(b1[j][x[i]]==1&&b1[j][y[i]]==1)
			{
				int n=0;
				for(int z=x[i];z<=y[i];z++)
				{
					n+=a1[y[i]][z];
				}
				ans = min(ans,n+m1[x[i]]+m1[y[i]]);
			}
			if(b1[j][x[i]]==1&&b1[j][y[i]]==0)
			{
				for(int z=j+1;z<=m;z++)
				{
					if(b1[z][x[i]]==0&&b1[z][y[i]]==1)
					{
						for(int l=1;i<n;i++)
						{
							if(b1[j][l]==1&&b1[z][l]==1)
							{
								int n,m;
								for(int o=x[i];o<=l;o++)
								{
									n+=a1[y[i]][o];
								}
								for(int o=x[i];o<=l;o++)
								{
									m+=a1[y[i]][o];
								}
								ans = min(ans,n+m+m1[x[i]]+m1[y[i]]);
							}
						}
					}
				}
			}
		}
	}
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
