#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
int ans=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=5000||m<=1e8)
	{
		sort(a+1,a+1+n);
		for(int i=2;i<=n;i++)
		{
			long long t=a[i];
			long long sum=0;
			for(int j=1;j<i;j++)
			{
				sum=sum+(t-a[j]);
			}
			if(sum<=m)
			{
				ans=max(ans,i);
			}
			else break;
		}
		cout<<ans;
	}
	else
	{
		sort(a+1,a+1+n,greater<long long>());
		for(int i=2;i<=n;i++)
		{
			long long t=a[i];
			long long sum=0;
			for(int j=1;j<i;j++)
			{
				sum=sum+(t-a[j]);
			}
			if(sum<=m)
			{
				ans=max(ans,i);
			}
			else break;
		}
		cout<<ans;
	}
	return 0;
}
