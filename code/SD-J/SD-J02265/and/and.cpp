#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],ans=0,tmp=0;
void dfs(int k,int s,int sum)
{
	if(s==m)
	{
		ans=max(ans,sum);
		return;
	}
	if(k==n+1)return;
	if(s==0)
	{
		sum=a[k];
		dfs(k+1,s+1,sum);
		sum=0;
		dfs(k+1,s,0);
	}
	else
	{
		tmp=sum;
		sum=sum&a[k];
		dfs(k+1,s+1,sum);
		sum=tmp;
		dfs(k+1,s,sum);
	}
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(i==1)ans=a[i];
		else ans=ans&a[i];
	}
	sort(a+1,a+n+1);
	if(m==1)
	{
		printf("%lld",a[n]);
		return 0;
	}
	if(m==n)
	{
		printf("%lld",ans);
		return 0;
	}
	if(m==2)
	{
		ans=0;
		int p=0;
		for(int i=1;i<=n;i++)
		{
			p=a[i];
			for(int j=i+1;j<=n;j++)
			{
				p=p&a[j];
				ans=max(ans,p);
			}
		}
		printf("%lld",ans);
		return 0;
	}
	if(n<=20)
	{
		ans=0;
		dfs(1,0,0);
		printf("%lld",ans);
		return 0;
	}
	else
	{
		ans=a[n];
		for(int i=n-1;i>=n-m+1;i--)
		{
			ans=ans&a[i];
		}
		printf("%lld",ans);
		return 0;
	}
	return 0;
}
