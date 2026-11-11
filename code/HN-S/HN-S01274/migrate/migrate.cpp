#include <bits/stdc++.h>
using namespace std;
long long x[1000010];
vector<int> v[1000010];
int dp[1000010];
int s[1000010];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--)
	{
		int n;
		long long d;
		scanf("%d%lld",&n,&d);
		for (int i=1;i<=n;i++)
			scanf("%lld",&x[i]);
		long long ans=0;
		for (int i=1;i<=n;i++)
		{
			dp[i]=0,s[i]=1;
			for (int j=i+1;j<=n;j++) dp[j]=INT_MAX,s[j]=0;
			for (int j=i+1;j<=n;j++)
			{
				int ss=0;
				int t=lower_bound(x+1,x+1+n,x[j]-d)-x;
				if(t>=j) break;
				for (int k=max(t,i);k<j;k++)
				{
					
					if(dp[k]+1<dp[j]) dp[j]=dp[k]+1,ss=s[k];
					else if(dp[k]+1==dp[j]) ss+=s[k];
				}
				s[j]=ss;
				if(ss==2) ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
