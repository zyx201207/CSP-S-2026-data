#include<bits/stdc++.h>
using namespace std;
struct stu
{
	char c;
	long long t;
}a[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long i,n,l,r,k=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i].t>>a[i].c;
	}
	l=1;
	r=n;
	while(l<r)
	{
		if(a[l].c!=a[r].c)
		{
			if(a[l].t<a[r].t)
			{
				k+=a[l].t;
				a[r].t-=a[l].t;
				a[l].t=0;
				l++;
			}
			else
			{
				if(a[l].t>a[r].t)
				{
					k+=a[r].t;
					a[l].t-=a[r].t;
					a[r].t=0;
					r--;
				}
				else
				{
					k+=a[r].t;
					a[l].t=0;
					a[r].t=0;
					r--;
					l++;
				}
			}
		}
		else
		{
			if(a[l].t<a[r].t)
			{
				a[r].t-=a[l].t;
				a[l].t=0;
				l++;
			}
			else
			{
				if(a[l].t>a[r].t)
				{
					a[l].t-=a[r].t;
					a[r].t=0;
					r--;
				}
				else
				{
					a[l].t=0;
					a[r].t=0;
					r--;
					l++;
				}
			}
		}
	}
	cout<<k;
	return 0;
}
