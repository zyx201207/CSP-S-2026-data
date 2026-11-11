#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long a[500001],b[500001];
bool cmp(long long x,long long y)
{
	return x<y;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,t=0;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n,cmp);
	for(long long i=1;i<=n;i++)
		b[i]=b[i-1]+a[i];
	long long j=1;
	for(long long i=1;i<=n;i++)
	{
		long long t1=1;
		if(i*a[i]-b[i]<=m)
		{
			t1=i;	
		}
		else
			for(;j<=n;j++)
			{
				if(m+a[i]*j-b[j]-i*a[i]+b[i]>=0)
				{
					t1=i-j;
					break;
				}
			}
		t=max(t1,t);
	}
	cout<<t;
return 0;	
} 
