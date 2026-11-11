#include<bits/stdc++.h>
using namespace std;
const int N=2e5+6;
int a[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(m==1)
	{
		int ans=-999;
		for(int i=1;i<=n;i++)
			ans=max(a[i],ans);
		cout<<ans;
	}
	else if(m==n)
	{
		int ans=a[1];
		for(int i=2;i<=n;i++)
			ans=ans&a[i];
		cout<<ans;
	}
	else if(m==2)
	{
		int ans=-999;
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
				ans=max(a[i]&a[j],ans);
		}
		cout<<ans;
	}
	else if(m==n-1)
	{
		int sum,ans=-999;
		for(int i=1;i<=n;i++)
		{
			sum=1<<30-1;
			for(int j=1;j<=n;j++)
			{
				if(i!=j)
					sum&=a[j];
			}
			ans=max(ans,sum);
		}
		cout<<ans;
	}
	else
	{
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
	}
	return 0;
}
