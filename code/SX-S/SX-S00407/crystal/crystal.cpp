#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,m1,s,maxx=LLONG_MIN,t=0,x,x1=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i==2)
		{
			x=a[i]-a[i-1];
		}
		if(i>2 && a[i]-a[i-1]!=x)
		{
			t=1;
		}
	}
	if(t==0)
	{
		for(int i=2;i<=n;i++)
		{
			x1=x1+(i-1)*x;
			if(x1>m)
			{
				cout<<i-1;
				return 0;
			}
		}
	}
	else
	{
		sort(a+1,a+n+1);
		for(int i=n;i>=1;i--)
		{
			m1=m;
			s=1;
			for(int j=i-1;j>=1;j--)
			{
				if(m1-(a[i]-a[j])>=0)
				{
					m1=m1-a[j];
					s++;
				}
				else
				    break;
			}
			maxx=max(maxx,s);
		}
		cout<<maxx;
	}
	return 0;
}