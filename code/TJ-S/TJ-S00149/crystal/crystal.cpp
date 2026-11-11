#include<bits/stdc++.h>
using namespace std;
struct c{
	long long a,b;
}l[500005];
bool cmp1(c x,c y)
{
	return x.a<y.a;
}
bool cmp2(c x,c y)
{
	if(x.b!=y.b)
	{
		return x.b<y.b;
	}
	else
	{
		return x.a<x.b; 
	}
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,cnt=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>l[i].a;
	}
	sort(l+1,l+n+1,cmp1);
	for(int i=2;i<n;i++)
	{
		l[i].b=l[i+1].a-l[i-1].a;
	}
	l[n].b=l[n].a-l[n-1].a;
	l[1].b=l[2].a-l[1].a;
	sort(l+1,l+n+1,cmp2);
	for(int i=1;i<n;i++)
	{
		m-=(l[i+1].a-l[i].a);
		if(m>=0)
		{
			l[i].a=l[i+1].a;
		}
		else
		{
			cout<<cnt+1;
			return 0;
		}
		for(int j=i-1;j>=1;j--)
		{
			m-=l[i].a-l[j].a;
			if(m>=0)
			{
				l[j].a=l[i].a;
			}
			else
			{
				cout<<cnt+1;
				return 0;
			}
			
		}
		cnt++;
	}
	cout<<cnt+1;
	return 0;
}
