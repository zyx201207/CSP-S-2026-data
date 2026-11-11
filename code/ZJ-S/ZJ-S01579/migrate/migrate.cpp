#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
long long c,T,n,m,a[N];
int dp[N][N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>m;
		int ans=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			dp[i][i]=1;
			for(int j=i+1;j<=n;j++)
			{
				if(a[i]+m>=a[j]) dp[i][j]=1;
				else if((a[j]-a[i])%m==0) dp[i][j]=1;
				else
				{
					int idx=lower_bound(a+1,a+n+1,a[j]-m)-&a[0];
//					cout<<idx<<"\n";
					for(int k=idx;k<j;k++)
					{
						dp[i][j]+=dp[i][k];
					}
				}
			}
		}
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=n;j++)
//			{
//				cout<<dp[i][j]<<" ";
//				if(dp[i][j]==2) ans++;
//			}
//			cout<<'\n';
//		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dp[i][j]=0;
		cout<<ans<<'\n';
	}
	return 0;
}