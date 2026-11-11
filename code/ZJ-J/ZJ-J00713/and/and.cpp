#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];
int ans=0;
void dfs(int sum,int len,int last)
{
	if(len==m)
	{
		ans=max(ans,sum);
		return ;
	}
	for(int i=last+1;i<=n;i++)
	{
		if(i==n&&len+1<m) return ;
		dfs((sum&a[i]),len+1,i);
	}
	return ;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=20)
	{
		for(int i=1;i<=n;i++)
		dfs(a[i],1,i);
		cout<<ans;
	}
	else if(m==1)
	{
		sort(a+1,a+n+1);
		cout<<a[n];
	}
	else if(m==2)
	{
		int ans1=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans1=max(ans1,(a[i]&a[j]));
			}
		}
		cout<<ans1;
	}
	else if(m==n)
	{
		int sum=a[1];
		for(int i=2;i<=n;i++) sum=(sum&a[i]);
		cout<<sum;
	}
	else
	{
		sort(a+1,a+n+1);
		int sum=a[n-m+1];
		for(int i=n-m+2;i<=n;i++) sum=(sum&a[i]);
		cout<<sum;
	}
	return 0;
}
