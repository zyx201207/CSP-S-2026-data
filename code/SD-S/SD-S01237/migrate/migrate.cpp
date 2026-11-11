#include<bits/stdc++.h>
using namespace std;
#define ing long long
const int N=5005;
int dp[N][N][2],t,n,d,x[N],ans,c;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		memset(dp,0,sizeof(dp));ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		for(int i=1;i<=n;i++)
			dp[i][i][0]=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<i;j++)
				if(x[i]-x[j]<=d) dp[j][i][1]=1;
				else
					for(int k=j+1;k<i&&x[k]-x[j]<=d;k++)
						if(x[i]-x[k]<=d)
						{
							dp[j][i][1]=dp[j][k][1]+1;
							break;
						}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<i;j++)
			{
				if(!dp[j][i][1]) continue;
				if(dp[j][i][1]==1)
				{
					dp[j][i][0]=1;
					continue;
				}
				for(int k=j;k<=i;k++)
					if(dp[j][k][1]&&x[i]-x[k]<=d&&dp[j][k][1]+1==dp[j][i][1])
						dp[j][i][0]+=dp[j][k][0];
				//cout<<i<<' '<<j<<' '<<dp[j][i][0]<<' '<<dp[j][i][1]<<'\n';
				if(dp[j][i][0]==2) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

