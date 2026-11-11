//袁骏逸 SN-J00837 西安市铁一中学 
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int ans=0;
void dfs(int s,int cnt,int yu)
{
	if(cnt>m)return ;
	if(cnt==m)
	{
		ans=max(ans,yu);
	}
	if(s>n)return ;
	dfs(s+1,cnt,yu);
	if(cnt==0)
	{
		yu=a[s];
		dfs(s+1,cnt+1,yu);
	}
	else dfs(s+1,cnt+1,yu&a[s]);
}
int sum1[200005],sum2[200005];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=20)
	{
		dfs(1,0,0);
		cout<<ans;
	}
	else if(n<=2000)
	{
		sort(a+1,a+n+1);
		if(m==1)cout<<a[n];
		if(m==n)
		{
			int ans=a[1];
			for(int i=2;i<=n;i++)ans=ans&a[i];
			cout<<ans;
		}
		if(m==2)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					ans=max(ans,a[i]&a[j]);
				}
			}
			cout<<ans;
		}
	}
	else
	{
		if(m==n-1)
		{
			sum1[1]=a[1];
			for(int i=2;i<=n;i++)sum1[i]=sum1[i-1]&a[i];
			sum2[n]=a[n];
			for(int i=n-1;i>=1;i--)sum2[i]=sum2[i+1]&a[i];
			for(int i=1;i<=n;i++)
			{
				if(i==1)
				{
					ans=max(ans,sum2[2]);
				}
				else if(i==n)
				{
					ans=max(ans,sum1[i-1]);
				}
				else ans=max(ans,sum1[i-1]&sum2[i+1]);
			}
			cout<<ans;
		}
		else 
		{
			sort(a+1,a+n+1);
			cout<<a[n-m+1];
		}
	}
	return 0;
}
