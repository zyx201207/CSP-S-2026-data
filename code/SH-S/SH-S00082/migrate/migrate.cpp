#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,x[2000001],d,sp,ans=0,f[5001][5001][2];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--)
    {
    	cin>>n>>d;
    	ans=0;
    	for(int i=1;i<=n;i++)
    	{
    		cin>>x[i];
		}
		if(c<=10)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=i;j<=n;j++)
				{
					f[i][j][0]=1e18;
					f[i][j][1]=0;
				}
			}
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					if(x[j]-x[i]>d)
						break;
					f[i][j][0]=1;
					f[i][j][1]=1;
					for(int k=1;k<i;k++)
					{
						if(f[k][j][0]==f[k][i][0]+f[i][j][0])
							f[k][j][1]+=f[k][i][1]*f[i][j][1];
						else if(f[k][j][0]>f[k][i][0]+f[i][j][0])
						{
							f[k][j][0]=f[k][i][0]+f[i][j][0];
							f[k][j][1]=f[k][i][1]*f[i][j][1];
						}
					}
				}
			}
			for(int i=1;i<=n-3;i++)
			{
				for(int j=i+3;j<=n;j++)
				{
					//cout<<i<<' '<<j<<' '<<f[i][j][0]<<' '<<f[i][j][1]<<'\n';
					if(f[i][j][1]==2)
						ans++;
				} 
			} 
			cout<<ans<<'\n';
			continue;
		}
		if(c==13||c==14)
		{
			for(int i=1;i<=n;i++)
			{
				if(abs(x[i]-x[n])<=d)
					break;
				if(x[i+2]-x[i]<=d&&x[i+3]-x[i+1]<=d&&x[i+3]-x[i]>d)
					ans++;
			}
			cout<<ans<<'\n';
			continue;
		}
	}
    return 0;
}

