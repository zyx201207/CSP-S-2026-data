// 吴鑫桐 西安市爱知中学 SN-J00627
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,a[1000000],ans1=0,f[1000000];
void dfs(ll x,ll ans2)
{
	if(x==k)
	{
		ans1=max(ans1,ans2);
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i]==0)
		{
			f[i]=1;
			dfs(x+1,ans2&a[i]);
			f[i]=0;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	if(k==1)
	{
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			ans=max(ans,a[i]);
		}
		cout << ans;
	}
	else if(k==2)
	{
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i!=j)
				{
					ans=max(ans,a[i] & a[j]);
				} 
			}
		}
		cout << ans;
	}
	else if(k==n-1)
	{
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			ll sum=1;
			for(int j=1;j<=n;j++)
			{
				if(i!=j)
				{
					sum=sum&a[j];
				}
			}
			ans=max(sum,ans);
		}
		cout << ans;
	}
	else if(k==n)
	{
		ll ans=1;
		for(int i=1;i<=n;i++)
		{
			ans=ans&a[i];
		}
		cout << ans;
	}
	else
	{
		dfs(0,1<<30-1);
		cout << ans1;
	}
	return 0;
}
