#include<bits/stdc++.h>
using namespace std;
int ok,cz[1000005],ans=0,c,T,n,m,a[1000005],i,j,z,dp[305][305],num[5005][5005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		ok=1;
		memset(dp,0x3f,sizeof(dp));
		memset(num,1,sizeof(num));
		ans=0;
		cin>>n>>m;
		for(i=1;i<=n;i++)cin>>a[i];
		for(i=1;i<=n;i++)dp[i][i]=0;
		for(i=1;i<n;i++)
		{
           	for(j=i;j<=n;j++)
           	    for(z=i;z<=j;z++)
                    if(a[j]-a[z]<=m)
                    {
                    	if(dp[i][z]+1<dp[i][j])
						{
						num[i][j]=1;
						dp[i][j]=dp[i][z]+1;
					    }
                    	else if(dp[i][z]+1==dp[i][j])num[i][j]++;
                    	else continue;
					}
	   }
	   for(i=1;i<=n;i++)
	   for(j=i+1;j<=n;j++)
	   if(num[i][j]==2)ans++;
	   cout<<ans<<"\n";
}
return 0;
	}
