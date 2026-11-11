#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,d=0,sum=0,q=-1,k=1,s=0,g=0;
	cin>>n>>m;
	long long a[n+5];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++)
	{
		if(a[i]-a[i-1]!=a[i-1]-a[i-2])
		{
			k=0;
		}
	}
	if(k==1)
	{
		s=a[2]-a[1];
		m/=s;
		while(m>0)
		{
			g++;
			m-=g;
			cout<<g<<" ";
		}
		if(m<0)
		{
			cout<<g;
			return 0;
		}
		else
		{
			cout<<g+1;
			return 0;
		}
	}
	for(int i=2;i<=n;i++)
	{
		d=0,sum=0;
		for(int j=i-1;j>=1;j--)
		{
			d=d+a[i]-a[j];
			if(d<=m)
			{
				sum++;
			}
			else
			{
				break;
			}
		}
		if(q<sum)
		{
			q=sum;
		}
	}
	cout<<q+1;
	return 0;
}
