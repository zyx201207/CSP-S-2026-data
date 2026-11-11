#include<bits/stdc++.h>
using namespace std;
long long rd()
{
	long long f=1,k=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		k=(k<<1)+(k<<3)+(c^48);
		c=getchar();
	}
	return f*k;
}
long long c,t,n,d,a[2000005],pr[2000005],dp[2000005],tim[2000005],sum;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=rd(),t=rd();
	while(t--)
	{
		sum=0;
		n=rd(),d=rd();
		for(int i=1;i<=n;i++)
		{
			a[i]=rd();
		}
		int j=n;
		for(int i=n;i>=1;i--)
		{
			while(a[i]-a[j-1]<=d&&j>1)
			{
				j--;
			}
			pr[i]=j;
		}
		for(int i=1;i<=n;i++)
		{
			dp[i]=tim[i]=1;
			for(int j=i+1;j<=n;j++)
			{
				dp[j]=0;
				long long str=max(1ll*i,pr[j]);
				tim[j]=tim[str]+1;
				for(int k=str;k<=min(str+2,1ll*j-1)&&tim[str]==tim[k];k++)
				{
					dp[j]+=dp[k];
				}
				if(dp[j]==2)
				{
					sum++;
				}
			}
		}
		cout<<sum<<"\n";
	}
}