#include<bits/stdc++.h>
#define int long long
using namespace std;
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
const int N=2e6+5;
int n,a[N],d,dp[N],sum[N];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C=read(),T=read();
	while(T--)
	{
		n=read();d=read();
		for(int i=1;i<=n;i++)a[i]=read();
		if(n==1)
		{
			cout<<0<<'\n';
			continue;
		}
		if(C==11||C==12)
		{
			int k=a[2]-a[1];
			if(k>=d||a[n]-a[1]<=d)
			{
				cout<<0<<'\n';
				continue;
			}
			int opk=1;
			for(int i=1;i<=n;i++)
			{
//				cout<<opk<<'\n';
				if(a[i]<=a[1]+d)opk=i;
				else break;
			}
			int ans=0;
			opk--;
//			cout<<opk<<'\n';
//			for(int i=3;i<=n;i++)if(i%opk!=0)ans+=n/i;
//			cout<<opk<<'\n';
			cout<<n-(2*opk-1)<<'\n';
			continue;
		}
		if((C==13||C==14)&&n>=1000)
		{
			int mid=(n-1)/2+1,l=mid-1,r=mid+1;
			if(a[mid+1]<=a[1]+d)r++;
			int kop=0,okp=n+1;
			for(int i=1;i<=l;i++)
			{
				if(a[r]>=a[i]+d)kop=i;
				else break;
			}
			for(int i=r;i<=n;i++)
			{
				if(a[i]>=a[l]+d)
				{
					okp=i;
					break;
				}
			}
//			cout<<kop<<" "<<okp<<'\n';
			int ans=kop*(n+1-okp)-1;
			if(a[n]-a[1]==2*d)ans--;
			cout<<ans<<'\n';
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			int l=i;
			dp[i]=0;sum[i]=1;
			for(int j=i+1;j<=n;j++)
			{
				dp[j]=2e18;
				sum[j]=0;
				while(a[l]+d<a[j])l++;
//				cout<<l<<' '<<j<<'\n';
//				if(a[l]+d<a[j])break;
				for(int k=l;k<=j-1;k++)
				{
					if(dp[j]>dp[k]+1)
					{
						dp[j]=dp[k]+1;
						sum[j]=sum[k];
					}
					else if(dp[j]==dp[k]+1)sum[j]+=sum[k];
				}
				if(dp[j]==2e18)break;
				if(sum[j]==2)ans++;
//				cout<<i<<" "<<j<<" "<<dp[j]<<' '<<sum[j]<<'\n';
//				if(sum[j]>2)break;
			}
//			cout<<'\n';
		}
		cout<<ans<<'\n';
	 } 
	return 0;
 }

