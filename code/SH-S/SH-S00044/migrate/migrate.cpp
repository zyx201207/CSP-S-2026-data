#include<bits/stdc++.h>
using namespace std;
long long t,n,d,a[2000005],dp[2000005],f[2000005],ans;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	cin>>t>>t;
	while(t--)
	{
		ans=0;
		memset(a,0,sizeof a);
		memset(dp,0,sizeof dp);
		memset(f,0,sizeof f);
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(long long l=1;l<n;l++)
		{
			memset(dp,0,sizeof dp);
			memset(f,0,sizeof f);
			dp[l]=1;
			for(long long i=l+1;i<=n;i++)
			{
				for(long long j=l;j<i;j++)
					if(a[j]+d>=a[i]&&(f[i]==0||f[i]==f[j]+1))
					{
						dp[i]+=dp[j];
						f[i]=f[j]+1; 
					}
			}
			for(long long i=1;i<=n;i++)
				if(dp[i]==2)
					ans++;
		}
		cout<<ans;
	}
	return 0;
}
