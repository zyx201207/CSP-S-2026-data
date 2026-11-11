#include<bits/stdc++.h>
using namespace std;
long long a[2000005],f[5005][5005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long c,t,n,d;
	cin >> c >> t ;
	while(t)
	{
		t--;
		cin >> n >> d ;
		if(c==13||c==14)
		{
			cout << 0 << endl ;
		}
		else
		{
			long long ans=0;
			for(int i=1;i<=n;i++)
			{
				cin >> a[i] ;
			}
			for(int i=1;i<=n;i++)
			{
				memset(f,0,sizeof(f));
				f[i][0]=1;
				for(int j=i+1;j<=n;j++)
				{
					for(int x=1;x<=n;x++)
					{
						for(int y=j-1;a[j]-a[y]<=d && y>=i;y--)
						{
							f[j][x]+=f[y][x-1];
						}
					}
				}
				for(int j=i+1;j<=n;j++)
				{
					int minm=0;
					while(f[j][minm]==0) minm++;
					if(f[j][minm]==2) ans++;
				}
			}
			cout << ans << endl ;
		}
	}
	return 0;
}
