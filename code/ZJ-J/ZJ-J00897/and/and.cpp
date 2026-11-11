#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans=-9e18;
bool b[200005],can_tp1=1,can_tp2=1;
void dfs1(long long i,long long sum)
{
	if(i>m)
	{
		ans=max(ans,sum);
		return;
	}
	for(long long j=1;j<=n;++j)
	{
		if(b[j]==0)
		{
			b[j]=1;
			dfs1(i+1,sum&a[j]);
			b[j]=0;
		}
	}
	return;
}
void dfs2(long long i)
{
	if(i>n-m)
	{
		long long sum=-9e18;
		for(long long j=1;j<=n;++j)
		{
			if(b[j]==1)
			{
				if(sum==-9e18)sum=a[j];
				else sum&=a[j];
			}
		}
		ans=max(ans,sum);
		return;
	}
	for(long long j=1;j<=n;++j)
	{
		if(b[j]==1)
		{
			b[j]=0;
			dfs2(i+1);
			b[j]=1;
		}
	}
	return;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(NULL);
	cin.tie(nullptr);
	cin>>n>>m;
	if(pow(2,floor(log2(n)))!=n)
	{
		can_tp2=0;
	}
	for(long long i=1;i<=n;++i)
	{
		cin>>a[i];
		if(pow(2,floor(log2(a[i]))+1)-1!=a[i])
		{
			can_tp1=0;
		}
		if(a[i]!=i-1)
		{
			can_tp2=0;
		}
	}
	if(can_tp1)
	{
		sort(a+1,a+1+n);
		cout<<a[n-m+1];
		return 0;
	}
	if(can_tp2)
	{
		cout<<0;
		return 0;
	}
	if(m<=n/2)
	{
		for(long long i=1;i<=n;++i)
		{
			b[i]=1;
			dfs1(2,a[i]);
			b[i]=0;
		}
	}
	else
	{
		for(long long i=1;i<=n;++i)
		{
			b[i]=1;
		}
		dfs2(1);
	}
	cout<<ans;
	return 0;
}