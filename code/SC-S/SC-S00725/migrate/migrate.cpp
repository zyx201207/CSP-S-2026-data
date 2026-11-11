#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n,d,x[10005],dp[5005][5005],kp[5005][5005],ans;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	for(int T=1;T<=t;T++)
	{
		ans=0;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dp[i][j]=998244353;
		for(int l=2;l<=n;l++)
		{
			for(int i=1;i<=n-l+1;i++)
			{
				int j=i+l-1;
				if(x[j]-x[i]<=d)dp[i][j]=1,kp[i][j]=1;
				else 
				{
					for(int k=i+1;k<=j-1;k++)
					if(x[k]-x[i]<=d)dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
					long long cnt=0;
					for(int k=i+1;k<=j-1;k++)if(x[k]-x[i]<=d&&dp[i][j]==dp[i][k]+dp[k][j])cnt+=kp[i][k]*kp[k][j];
					if(cnt==2)
					{
						ans++;
//						cout<<"gx "<<i<<" "<<j<<endl;
					}
//					cout<<i<<" "<<j<<endl;
//					cout<<cnt<<endl;
					kp[i][j]=cnt;
				}
//				cout<<"qz "<<i<<" "<<j<<" "<<dp[i][j]<<endl;
				
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
0 1
7 666666666666666663


 -1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
*/