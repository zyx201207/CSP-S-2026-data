#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int f(int x)
{
	int ans=0;
	while(x)
	{
		if(x%2)
		{
			ans++;
		}
		x/=2;
	}
	return ans;
}
int f1(int x)
{
	int ans=0;
	while(x)
	{
		x/=2;
		ans++;
	}
	return ans;
}
struct node
{
	int x,one,id;
}a[200005];
bool cmp(node a,node b)
{
	if(a.one!=b.one)
	{
		return a.one>b.one;
	}
	return a.x>b.x;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x;
		a[i].one=f(a[i].x);
		a[i].id=f1(a[i].x)-1;
	}
	if(f(n)==1)
	{
		bool flag=1;
		for(int i=1;i<=n;i++)
		{
			if(a[i].x!=i-1)
			{
				flag=0;
			}
		}
		if(flag)
		{
			if(m>n/2)
			{
				cout<<0;
				return 0;
			}
			else
			{
				cout<<n-m;
				return 0;
			}
		}
	}
	sort(a+1,a+n+1,cmp);
	int ans=a[1].x;
	for(int i=1;i<=m;i++)
	{
		ans&=a[i].x;
	}
	if(a[m].id!=a[m-1].id)
	{
		for(int i=m+1;i<=n;i++)
		{
			if(a[m-1].id==a[i].id)
			{
				ans&=a[i].x;
				cout<<ans;
				return 0;
			}
		}
	}
	ans&=a[m].x;
	cout<<ans;
	return 0;
}
