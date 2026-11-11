#include<bits/stdc++.h>
using namespace std;
int a[200010];
int l[32];
long long k[21];
long long count(long long a)
{
	long long sum=1;
	if(a==0)
	{
		return 1;
	}
	for(int i=0;i<a;i++)
	{
		sum*=2;
	}
	return sum;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >>n >>m;
	int u=0;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		u=max(a[i],u);
	}
	if(m==n)
	{
		int p=a[0];
		for(int i=1;i<n;i++)
		{
			p=p&a[i];
		}
		cout << p;
	}
	else if(m==1)
	{
		int ma=0;
		for(int i=0;i<n;i++)
		{
			if(ma<a[i])
			{
				ma=a[i];
			}
		}
		cout << ma;
	}
	else if(m==2)
	{
		int ans=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(i!=j)
				{
					 ans=a[i]&a[j];
				}
			}
		}
		cout << ans;
	}
	else if(m==n-1)
	{
		int j=u,ma=0;
		for(int i=0;i<n;i++)
		{
			for(int o=0;o<n;o++)
			{
				if(o!=i)
				{
					j=j&a[o];
				}
			}
			if(ma<j)
			{
				ma=j;
			}
		}
		cout << ma;
	}
	else{
		sort(a,a+n);
		int p=a[n-1];
		for(int i=n-2;i>=n-m;i--)
		{
			p=p&a[i];
		}
		cout << p;
	}
	return 0;
}
