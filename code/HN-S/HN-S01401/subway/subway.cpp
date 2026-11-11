#include<bits/stdc++.h>
using namespace std;
int dp[4005][4005],a[500005],b[500005];
long long w[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int qq,n,m,d,q;
	cin>>qq>>n>>m>>d>>q; 
	for(int i=1;i<=m;i++)cin>>w[i];	
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=n;i++)
	{
		int T;
		cin>>T;
		for(int j=1;j<=T;j++)cin>>a[j]>>b[j];
		for(int xx=1;xx<=T;xx++)
		{
			for(int yy=xx+1;yy<=T;yy++)
			{
				dp[a[xx]][a[yy]]=min(dp[a[xx]][a[yy]],b[xx]+b[yy]);	
				dp[a[yy]][a[xx]]=dp[a[xx]][a[yy]];
			}
		}
	}
	for(int i=1;i<=m;i++)dp[i][i]=0;
	for(int k=1;k<=m;k++)
	{
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(i!=j)
				{
					dp[i][j]=min(dp[i][k]+dp[k][j],dp[i][j]);
					dp[k][i]=dp[i][k];
				}
				
			}
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<dp[x][y]+w[x]+w[y]<<endl;
	}
	return 0;
 } 
 
