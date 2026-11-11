#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[1010],dp[1010][1010];
void dfs(int k,int p)
{
	for(int i=k-1;i>=1;i--)
	  if(x[k]-x[i]>d)
	  {
		dp[i+1][p]++;
		dfs(i+1,p);
		break;
	  }
} 
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) scanf("%d",&x[i]);
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++) dfs(i,i);
		int ans=0;
		for(int i=1;i<=n;i++)
		  for(int j=i+1;j<=n;j++)
			if(dp[i][j]>=2) ans+=dp[i][j]*(dp[i][j]+1)/2;
		cout<<ans<<endl;
	}
	return 0;
}
