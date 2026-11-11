#include<bits/stdc++.h>
using namespace std;
const int N=2e6+100;
int a[N];
int dp[5010][5010];

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		memset(a,0,sizeof a);
		for(int i=0;i<=5000;i++)
		{
			for(int j=0;j<=5000;j++)
			{
				dp[i][j]=0;
			}
		}
		dp[1][1]=1;
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int t=1;t<=n;t++)
		{
			
		for(int i=1;i<=n;i++)
	    {
		
			for(int j=2;j<=n;j++)
			{
				if(a[j]-a[i]>d)break;
				else
				{
					dp[j][t]+=dp[i][t-1];
				}
			}
		
			/*for(int j=i;j>=1;j--)
			{
				if(a[i]-a[j]>d)break;
				else  dp[][]+=dp[j];
			}*/
			
	    }
	}
	   for(int i=1;i<=n;i++)
	   {
		   if(dp[n][i]!=0)
		   {
			    cout<<(dp[n][i]*dp[n][i]-1)/2<<endl;
			    break;
		   }
	   }
	   
	   
	}
	return 0;
}
