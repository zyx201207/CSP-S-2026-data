#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long ans=0,sum=0,c=0;
	for(int i=1;i<=n;i++)
	{
		if(i==1)
		{
			ans=1;
			sum=1;
			c=0;
			continue;
		}
		if(a[i]==a[i-1])
		{
			sum++;
			ans=max(ans,sum);
			continue;
		}
		c+=sum*(a[i]-a[i-1]);
		sum++;
		if(c>m)
		{
			while(c>m)
			{
				c-=a[i]-a[i-sum];
				sum--;	
			}			
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}
