#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long int n,d,ans,c,t,a[N],dp[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	cin>>c>>t;
	int i,j;
	while(t--)
	{
		ans=0;
		
		cin>>n>>d;
		for(i=1;i<=n;i++)
		cin>>a[i];
		if(a[2]-a[1]>d)
		{
			cout<<0<<endl;
			continue;
		}
		else
		{
			memset(dp,0x7f,sizeof(dp));
			dp[1]=0;int cnt=0;
			for(i=2;i<=n;i++)
			{
				
				if(i<=d){
					for(j=1;j<i;j++)
					{
						if(dp[i]==dp[j]+1)
						{
							cnt++;
						}
						dp[i]=min(dp[i],dp[j]+1);
					}
					
					if(cnt==1)
					ans++;
				}
				else
				{
					for(j=i-d;j<i;j++)
					{
						if(dp[i]==dp[j]+1)
						{
							cnt++;
						}
						dp[i]=min(dp[i],dp[j]+1);
					}
					//cout<<dp[i]<<" ";
					if(cnt==1)
					ans++;
				}
			}
			cout<<ans<<endl;
		}
		
	}
	return 0;
}

