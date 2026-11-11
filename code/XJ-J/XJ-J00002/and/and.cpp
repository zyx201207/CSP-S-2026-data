#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],d;
long long an(int x,int y)
{
	string a,b,c;
	long long h=0,a1=0,b1=0,c1=0;
	for(long long i=0;x>0;i++)
	{
		a[i]=x%2+'0';
		a1++;
		x/=2;
	}
	
	for(long long i=0;y>0;i++)
	{
		b[i]=y%2+'0';
		b1++;
		y/=2;
	}
	
	c1=min(a1,b1);
	for(long long i=0;i<c1;i++)
	{
		if(a[i]=='1'&&b[i]=='1')
		{
			c[i]='1';
		}
		else
		{
			c[i]='0';
		}
	}
	for(long long i=0;i<c1;i++)
	{
		long long p=1;
		for(int j=1;j<=i;j++)
		{
			p*=2;
		}
		h+=p*(c[i]-'0');
	}
	return h;
}
void f(long long j,long long t,long long z)
{
	if(t==m)
	{
		d=max(d,z);
		return;
	}
	
	for(long long i=j+1;i<=n;i++)
	{
		f(i,t+1,an(z,a[i]));
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(long long i=1;i<=n-m+1;i++)
	{
		f(i,1,a[i]);
	}
	
	cout<<d;
	return 0;
}
