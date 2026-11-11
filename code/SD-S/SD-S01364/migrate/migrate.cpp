#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
long long c,T,n,d,x[3005],dp[3005][3005],cnt[3005][3005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)dp[i][j]=0x3f3f3f3f3f3f3f3f;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(x[j]-x[i]<=d)dp[i][j]=dp[j][i]=1,cnt[i][j]=1;
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(dp[i][k]+dp[k][j]<dp[i][j])
					{
						dp[i][j]=dp[i][k]+dp[k][j];
						cnt[i][j]=cnt[i][k]*cnt[k][j];
					}
					else if(dp[i][k]+dp[k][j]==dp[i][j])cnt[i][j]+=cnt[i][k]*cnt[k][j];//,cout<<k<<' '<<i<<' '<<j<<' '<<cnt[i][j]<<'\n';
				}
			}
		}
		long long ans=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)ans+=(cnt[i][j]==2);//,cout<<i<<' '<<j<<' '<<cnt[i][j]<<'\n';
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)dp[i][j]=0x3f3f3f3f3f3f3f3f,cnt[i][j]=0;
			x[i]=0;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
