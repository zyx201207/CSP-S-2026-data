#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long cha[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,i,j,x,y;
	long long s=0,f=0,z=0;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i!=1)
		{
			x=a[i]-a[i-1];
			if(f==0)
			{
				y=a[i]-a[i-1];
			}
			if(x==y) f++;
		} 
	}
	sort(a+1,a+n+1);
	long long t;
	if(f==n-1)
	{
		while(s+x<=m)
		{
			s+=x;
			x+=y;
			z++;
		}
		if(m>=x)
		{
			cout<<z+1;
		}	
	}
	else
	{
		cout<<0;
	}
	return 0;
} 
