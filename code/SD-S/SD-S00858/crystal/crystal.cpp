#include<iostream>
#include<algorithm>
using namespace std;
long long a[500005],b[500005],c[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)
		b[i]=a[i+1]-a[i];
	for(int i=1;i<n;i++)
		c[i]=c[i-1]+b[i];
	int z=0;
	for(int i=2;i<n;i++)
	{
		if(b[i-1]==b[i])
			z++;
	}
	if(z==n-2)
	{
		if(b[1]==0)
		{
			cout<<n;
			return 0;
		}
		long long r=m;
		long long l=1;
		while(r>=0)
		{
			r-=b[1]*l;
			l++;
		}
		l--;
		cout<<min(l,n);
		return 0;
	}
	int l=1,r=1;
	int y=r-l+1;
	long long x=b[1];
	while(r<n)
	{
		if(x<=m)
		{
			r++;
			x=x+b[r]*(r-l+1);
			y=max(y,r-l+1);
		}
		else
		{
			x=x-c[r]+c[l-1];
			l++;
		}
	}
	cout<<y;
	return 0;
}
