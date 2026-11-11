#include<bits/stdc++.h>
using namespace std;
long long ans;
struct p
{
	long long l,m;
}a[200010];
bool sorrt(p x,p y)
{
	return x.m>y.m;
}
bool sa(p x,p y)
{
	return x.l>y.l;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.ans","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].l;
		long long x=a[i].l;
		for(;x;x/=2)
		{
			if(x%2)
			{
				a[i].m++;
			}
			
		}
	}
	if(n==m)
	{
		ans=a[1].l;
		for(int i=2;i<=n;i++)
		{
			ans&=a[i].l;
		}
		cout<<ans;
	}
	else if(m==1)
	{
		sort(a+1,a+n+1,sa);
		cout<<a[n].l;
	}
	else
	{
		sort(a+1,a+n+1,sorrt);
		ans=a[1].l;
		for(int i=2;i<n;i++)
		{
			ans&=a[i].l;
		}
		cout<<ans;
	}
	return 0;
}
