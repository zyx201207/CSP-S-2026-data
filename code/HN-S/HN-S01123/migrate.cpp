#include<bits/stdc++.h>
using namespace std;
int c,t,n,dp[2000005],cnt[2000005];
long long d,a[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>t;
	if(c<=10)
	{
		while(t--)
		{
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>a[i];
			int ans=0;
			for(int id=1;id<=n;id++)
			{
				for(int i=id;i<=n;i++)dp[i]=cnt[i]=0;cnt[id]=1;
				for(int i=id+1,j=id;i<=n;i++)
				{
					while(a[i]-a[j]>d)j++;
					if(i==j)break;
					dp[i]=dp[j]+1;cnt[i]=cnt[j];
					for(int k=j+1;dp[k]==dp[k-1]&&cnt[i]<=3;k++)cnt[i]+=cnt[k];
					ans+=cnt[i]==2;cnt[i]=min(cnt[i],3);
				}
			}
			cout<<ans<<'\n';
		}
		return 0;
	}
	if(c==11||c==12)
	{
		while(t--)
		{
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>a[i];
			long long ans=0;
			for(int i=1;i<=n;i++)dp[i]=cnt[i]=0;cnt[1]=1;
			for(int i=2,j=1;i<=n;i++)
			{
				while(a[i]-a[j]>d)j++;
				if(i==j)break;
				dp[i]=dp[j]+1;cnt[i]=cnt[j];
				for(int k=j+1;dp[k]==dp[k-1]&&cnt[i]<=3;k++)cnt[i]+=cnt[k];
				ans+=(cnt[i]==2)*(n-i+1);cnt[i]=min(cnt[i],3);
			}
			cout<<ans<<'\n';
		}
		return 0;
	}
	return 0;
}
