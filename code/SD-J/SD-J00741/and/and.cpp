#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main() 
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		int ma=0;
		for(int i=1;i<=n;i++)
		{
			ma=max(ma,a[i]);
		}	
		cout<<ma;
		return 0;
	}
	if(m==n)
	{
		int x=a[1];
		for(int i=2;i<=n;i++)
		{
			x&=a[i];
		}
		cout<<x;
		return 0;
	}
	if(m==2)
	{
		int ma1=0;
		for(int i=1;i<=n;i++)
		{
			ma1=max(ma1,a[i]);
		}
		int ma2=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==ma1)continue;
			ma2=max(ma2,a[i]);
		}
		cout<<(ma1&ma2);
		return 0;
	}
	if(m==n-1)
	{
		int mi=2^30+2;
		for(int i=1;i<=n;i++)
		{
			mi=min(mi,a[i]);
		}
		int x=a[1];
		if(a[1]==mi)
		{
			x=a[2];
			for(int i=3;i<=n;i++)
			{
				x&=a[i];
			}
			cout<<x;
			return 0;
		}
		else
		{
			for(int i=2;i<=n;i++)
			{
				if(a[i]!=mi)
				{
					x&=a[i];	
				}
			}
			cout<<x;
			return 0;
		}
	}
	cout<<1;
	return 0;
}
