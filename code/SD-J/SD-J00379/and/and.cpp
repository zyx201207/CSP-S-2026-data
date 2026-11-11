#include<bits/stdc++.h> 
using namespace std;
int n,m,num[200005];
int dp[2005][2005];
bool dpx[2005][2005];
//max of dp[Ñ¡m¸ö] 
int ans=0;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>num[i];
	
	}
	for(int i=1;i<=n;i++)
	{
		dp[i][1]=num[i];
	}
	for(int i=1;i<=n;i++)
	{	
		for(int j=1;j<=m;j++)
		{
			int a=0;
			for(int k=1;k<=n;k++)
			{
				if(k==i||dpx[i][k])continue;
		
				if(dp[i][j]<(dp[i][j-1]&num[k]))
				{
					dp[i][j]=dp[i][j-1]&num[k];
					a=k;
				}
			dpx[i][a]=1;
			}
			
		}
	}
	for(int i=1;i<=n;i++)
	{
		ans=max(dp[i][m],ans);
	}
	cout<<ans;
}
