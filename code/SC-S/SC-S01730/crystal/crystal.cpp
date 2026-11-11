#include<bits/stdc++.h>
using namespace std;
long long m,n,sum=0,x=1,y;
long long a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	y=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if (a[1]<0)
	{
		int l=abs(a[1]);
		for(int p=1;p<=n;p++)
		{
			a[p]+=l;
		}
	}
	if(a[1]>0)
	{
		int k=abs(a[1]);
		for(int o=1;o<=n;o++)
		{
			a[o]-=k;
		}
	}
    for(int i=1;i<=n;i++)
	{
		sum+=a[i];
	}
	if(y>x)
	{
	    while(sum>m)
	    {
		    long long x1=a[x+1]-a[x];
		    long long x2=a[y]-a[y-1];
		    if(x1>x2)
		    {
			    x++;
		    }
		    else
		    {
			    y--;
		    }
			sum=0;
			if (a[x]<0)
			{
				int l=abs(a[x]);
				for(int p=x;p<=y;p++)
				{
					a[p]+=l;
				}
			}
			else if(a[x]>0)
			{
				int k=abs(a[x]);
				for(int o=x;o<=y;o++)
				{
					a[o]-=k;
				}
			}
			for(int i=x;i<=y;i++)
			{
				sum+=a[i];
			}
	    }
	}
	if (y<x)
	{
		cout<<"1";
	}
	else
	{
	    cout<<y-x+1;
	}
	return 0;
}
