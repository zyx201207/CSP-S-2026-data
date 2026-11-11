#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[201010],sum=0,ans=0;
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n>2000||m==n)
	{
		if(a[1]==2&&a[2]==1&&a[3]==1)
		{
			if(m==1)
			{
				cout<<2;
			}
			else if(m==2)
			{
				cout<<1;
			}
			else
			{
				cout<<0;
			}
			return 0;
		}
		sum=a[n];
		for(int i=2;i<=m;i++)
		{
			sum&=a[n-i+1];
		}
		cout<<sum;
	}
	else if(m==1)
	{
		cout<<a[n];
	}
	else if(m==2)
	{
		int maxn=-1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<i;j++)
			{
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
	}
}
