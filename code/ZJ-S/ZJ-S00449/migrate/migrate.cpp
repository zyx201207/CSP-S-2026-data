#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005][4],c,t,x[1005],a[1005][1005];
int main()
{
 	ios::sync_with_stdio(false);
 	cin.tie(0);
 	freopen("migrate.in","r",stdin);
 	freopen("migrate.out","w",stdout);
 	cin>>c>>t;
 	while(t--)
 	{
 		int n,ans=0;
 		long long d;
 		memset(dp,0,sizeof dp);
 		cin>>n>>d;
 		for(int i=1;i<=n;i++)
 		{
 			cin>>x[i];
		 }
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				a[i][j]=x[j]-x[i];
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=i;j++)
			{
				if(a[j][i]>=d)
				{
					dp[j][i][0]+=1;
					dp[j][i-1][1]+=1;
					for(int k=1;k<j;k--)
					{
						if(a[k][j]<d)
						{
							dp[j][i-1][2]+=dp[k][j][0];
							dp[j][i][3]+=dp[k+1][j][1];
							break;
						}
					}
					break;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=i;j++)
			{
				ans+=dp[j][i][2];
				ans+=dp[j][i][3];
			}
		}
		cout<<ans<<endl;
	 }
 	return 0;
}
/*for(int i=2;i<=n;i++)
		{
			for(int k=1;k+i-1<=n;k++)
			{
				int j=i+k-1;
				if(a[j]-a[i]<=d)
				{
					dp[i][j][]
				}
				for(int l=k+1;l<=j;l++)
				{
					
				}
			}
		}*/