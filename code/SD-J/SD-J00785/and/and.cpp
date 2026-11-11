#include<bits/stdc++.h>
using namespace std;
long long a[200010];
bool cmp(long long x,long long y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long i,j,n,m,t,s;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		t=-1;
		for(i=1;i<=n;i++)
		{
			t=max(t,a[i]);
		}
		cout<<t;
		return 0;
	}
	if(m==n)
	{
		t=a[1];
		for(i=2;i<=n;i++)
		{
			t=t&a[i];
		}
		cout<<t;
		return 0;
	}
	if(m==2)
	{
		t=-10;
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				t=max(t,a[i]&a[j]);
			}
		}
		cout<<t;
		return 0;
	}
	if(m==n-1)
	{
		t=a[1];
		s=-10;
		for(j=1;j<=n;j++)
		{
			if(j==1)
			{
				t=a[2];
			}
			else
			{
				t=a[1];
			}
			for(i=1;i<=n;i++)
			{
				if(i!=j)
				{
					t=t&a[i];
				}
			}
			s=max(s,a[i]&a[j]);
		}
		cout<<s;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	t=a[1];
	for(i=2;i<=m;i++)
	{
		t=t&a[i];
	}
	cout<<t;
	return 0;
}
