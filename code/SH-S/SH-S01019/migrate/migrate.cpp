#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
int n,c,t;
ll d,a[2000005],ans;
int dp[2000005],tot[2000005],pos;
ll cnt[2000005];
namespace c1
{
	void solve()
	{
		ans=0;
		for(int i=1;i<=n;i++)
		{
			memset(dp,0,sizeof(dp));
			memset(cnt,0,sizeof(cnt));
			memset(tot,0,sizeof(tot));
			dp[i]=0;
			cnt[i]=1;
			tot[0]=1;
			pos=i;
			for(int j=i+1;j<=n;j++)
			{
				while(a[j]-a[pos]>d)
				{
					tot[dp[pos]]-=cnt[pos];
					pos++;
				}
				if(pos==j)break;
				dp[j]=dp[pos]+1;
				cnt[j]=tot[dp[pos]];
				tot[dp[j]]+=cnt[j];
				if(cnt[j]==2)ans++;
			}
		}
		printf("%lld\n",ans);
	}
}
namespace c2
{
	void solve()
	{
		memset(dp,0,sizeof(dp));
		memset(cnt,0,sizeof(cnt));
		memset(tot,0,sizeof(tot));
		dp[1]=0;
		cnt[1]=1;
		tot[0]=1;
		pos=1;
		ans=0;
		for(int i=2;i<=n;i++)
		{
			while(a[i]-a[pos]>d)
			{
				tot[dp[pos]]-=cnt[pos];
				pos++;
			}
			if(pos==i)break;
			dp[i]=dp[pos]+1;
			cnt[i]=tot[dp[pos]];
			tot[dp[i]]+=cnt[i];
			if(cnt[i]==2)ans+=n-i+1;
		}
		printf("%lld\n",ans);
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		scanf("%d %lld",&n,&d);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",a+i);	
		}	
		if(c<=10)
		{
			c1::solve();
			continue;
		}
		if(c<=12)
		{
			c2::solve();
			continue;
		}
		printf("0\n"); 
	}
	
 } 
