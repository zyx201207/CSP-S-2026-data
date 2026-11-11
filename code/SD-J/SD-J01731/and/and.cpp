#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],lg[40],c[40],ans=2147483647;
void f(int x)
{
	for(int i=31;i>=0;i--)
	{
		if(lg[i]<x)
		{
			x-=lg[i];
			c[i]++;
		}
	}
}
bool find(int x,int y)
{
	for(int i=31;i>y;i--)
		if(lg[i]<x)
			x-=lg[i];
	return x>=lg[y];
}
int main()
{	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	lg[0]=1;
	for(int i=1;i<=31;i++)
	{
		lg[i]=lg[i-1]*2;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f(a[i]);	
	} 
	if(m==1)
	{
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	if(m==2)
	{
		ans=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
			{
				long long an=a[i]&a[j];
				ans=max(ans,an);
			}
		cout<<ans;
		return 0;
	}
	if(m==n)
	{
		for(int i=1;i<=n;i++)
			ans&=a[i];
		cout<<ans;
		return 0;
	}
	int t=-1;
	for(int i=31;i>=0;i--)
	{
		if(c[i]>=m)
		{
			t=i;
			break;
		}
	}
	if(t==-1)cout<<0;
	else
	{
		for(int i=n;i>=1;i--)
		{
			if(find(a[i],t))
			{
				ans&=a[i];
			}
			if(m==0)break;
		}
		cout<<ans;
	}
	return 0;	
} 
