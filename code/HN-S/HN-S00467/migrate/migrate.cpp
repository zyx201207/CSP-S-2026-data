#include<bits/stdc++.h>
using namespace std;
long long int t,c,n,d,x[2000010],dp[5010][5010],ans;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		memset(dp,0,sizeof(dp));
		cin>>n>>d;
		for(long long int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		for(long long int i=1;i<n;i++)
		{
			for(long long int j=i+1;j<=n;j++)
			{
				if((x[j]-x[i])%d!=0)
				{
					dp[i][j]+=(x[j]-x[i]-1)/d+1;
				}
			}
		}
		for(long long int i=1;i<n;i++)
		{
			for(long long int j=i+1;j<=n;j++)
			{
				if(dp[i][j]==2)
				{
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
