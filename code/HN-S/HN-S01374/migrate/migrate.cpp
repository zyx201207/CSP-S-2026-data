#include<bits/stdc++.h>
#define int long long
using namespace std;
const int cxk=5000+5;
int n,k[cxk],s[cxk],x[cxk],d,t,c,dp[cxk][cxk],ans,f[cxk][cxk];
void help()
{
	ans=0;
	memset(f,0,sizeof(dp));
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		cin>>x[i];
	for(int i=1;i<=n;i++)
	{
		dp[i][i]=0;
		f[i][i]=1;
		for(int j=i+1;j<=n;j++)
			if(x[j]-x[i]<=d)
				dp[i][j]=1;
			else
				dp[i][j]=1e9;
	}
	for(int i=1,lt,rt,mid;i<=n;i++)
	{
		lt=i-1,rt=n+1;
		while(lt+1<rt)
		{
			mid=(lt+rt)/2;
			if(x[mid]-x[i]<=d)
				lt=mid;
			else
				rt=mid;
		}
		k[i]=lt;
	}
	for(int len=2;len<=n;len++)
		for(int i=1,j;i+len-1<=n;i++)
		{
			j=i+len-1;
			for(int r=i+1;r<=min(k[i],j);r++)
			{
				if(dp[i][j]>dp[r][j]+1)
				{
					dp[i][j]=min(dp[i][j],1+dp[r][j]);
					f[i][j]=1;
				}
				else if(dp[i][j]==dp[r][j]+1)
					f[i][j]++;
			}
		}
	
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			ans+=(f[i][j]==2);
			//cout<<dp[i][j]<<"\n";
	cout<<ans<<"\n";
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	for(cin>>c>>t;t--;help());
	return 0;
}
/*
0 1
4 2
1 2 3 4

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
