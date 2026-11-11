#include<bits/stdc++.h>
using namespace std;
int n,dp[500005];
long long a[500005],m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	dp[1]=1;
	for(int i=2;i<=n;i++)
	{
		dp[i]=dp[i-1]+1,m-=(a[i]-a[i-1])*(dp[i]-1);
		if(m<0)
		{
		 	dp[i]--;
		 	int cnt=dp[i];
		 	for(int j=i-cnt;j<i;j++)
			{
				m+=a[i]-a[j];
				if(m<0) dp[i]--;
				else break;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,dp[i]);
	cout<<ans;
	return 0;
}