#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m;
int a[N],cnt[N],sum[N],vis[N],t,ans,num;
void dfs(int u)
{
	if(t>m)
	{
		ans=0xfffff;
		for(int i=1;i<=n;i++)
		{
			if(vis[i]==1)
			{
				ans=ans&a[i];
			}
		}
		num=max(num,ans);
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			vis[i]=1;
			t++;
			dfs(i);
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==m)
	{
		int cnt=a[1];
		for(int i=2;i<=n;i++)
		{
			cnt=cnt&a[i];
		}
		cout<<cnt;
		return 0;
	}
	if(m==n-1)
	{
		sum[0]=0xfffff,cnt[n+1]=0xfffff;
		sum[1]=a[1],cnt[1]=a[n];
		for(int i=2;i<=n;i++)
		{
			sum[i]=sum[i-1]&a[i];
		}
		for(int i=n-1;i>=1;i--)
		{
			cnt[i]=cnt[i+1]&a[i];
		}
		int ans=-1000000;
		for(int i=1;i<=n;i++)
		{
			int x=sum[i-1]&cnt[i+1];
			ans=max(ans,x);
		}
		cout<<ans;
		return 0;
	}
	if(m==1)
	{
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			sum=max(sum,a[i]);
		}
		cout<<sum;
		return 0;
	}
	if(m==2)
	{
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(j==i) continue;
				sum=max(sum,a[i]&a[j]);
			}
		}
		cout<<sum;
		return 0;
	}
	vis[0]=1;
	dfs(0);
	cout<<num;
	return 0;
}
