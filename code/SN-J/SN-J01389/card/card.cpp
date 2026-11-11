#include<bits/stdc++.h>
using namespace std;



int n,m;
int vis[500007];
int dp[500007];
int a[500007];
long long ans[500007];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int k=1;k<=n;k++)
	{
		memset(dp,0,sizeof(dp));
		memset(vis,0,sizeof(vis));
		for(int i=k;i<=n;i++)
		{
			if(dp[a[i]]<i&&dp[a[i]]!=0&&vis[i]!=1)
			{
				for(int j=dp[a[i]];j<=i-1;j++)
				{
					vis[j]=1;
					dp[j]=0;
				}
				dp[a[i]]=i;
				vis[i]=0;
				
			
			}
			else
			{
				if(vis[i]==0&&dp[a[i]]==0)
				{
					dp[a[i]]=i;
				
				}
				
			}
		}
		for(int i=k;i<=n;i++)
		{
			if(vis[i]==0)
			{
				ans[a[i]]++;
			
				
			}
		}
	
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	} 
	
	return 0;
}
