#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	a[0]=0;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long max=-1,s=0;
	for(long long i=1;i<=n;i++)
	{
		for(long long j=i;j<=n;j++)
		{
		    long long p=j-i;
			s=a[j]*p;
			for(long long i1=i;i1<j;i1++)
			{
				s-=a[i1];
			}
            if(s>m)
            {
                break;
            }
			if(p>=max)
			{
				max=p;
			}
		}
	}
	cout<<max+1;
	return 0;
}
