#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,ans;
ll a[200005];
void dfs(ll x,ll sum,ll cnt)
{
	if(cnt==m)
	{
		if(sum==1048575)
		{
			return ;
		}
		ans=max(sum,ans);
		return ;
	}
	if(x>n) return ;
	dfs(x+1,sum&a[x],cnt+1);
	dfs(x+1,sum,cnt);
	return ;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			ans=max(a[i],ans);
		}
		cout<<ans;
	}
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=m;j++)
			{
				ans=max(a[i]&a[j],ans);
			}
		}
		cout<<ans;
	}
	else if(m==n)
	{
		ans=a[1];
		for(int i=2;i<=n;i++)
		{
			ans=ans&a[i];
		}
		cout<<ans;
	}
	else if(n<30)
	{
		a[0]=1048575;
		dfs(1,1048575,0);
		cout<<ans;
	}	
	else if(m==n-1)
	{
		sort(a+1,a+1+n);
		ans=a[2];
			for(int i=3;i<=m;i++)
			{
				ans=ans&a[i];
			}
			cout<<ans;
	}
	else if(n>=30)
	{
		int f1=1;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>=4)
			{
				f1=0;
			}
		}
		if(f1)
		{
			cout<<3;
		}
		else
		{	
			sort(a+1,a+1+n);
			ans=a[1];
			for(int i=2;i<=m;i++)
			{
				ans=ans&a[i];
			}
			cout<<ans;
		}
	}
	return 0;
}