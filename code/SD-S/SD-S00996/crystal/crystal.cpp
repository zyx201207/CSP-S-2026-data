#include<bits/stdc++.h>
using namespace std;
#define N 500055
int n;
long long m;
long long a[N];
bool check(long long x)
{
	long long sum=0;
	for(long long i=1;i<=x;i++)
	{
		sum+=(a[x]-a[i]);
	}
	return sum<=m;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	long long l=1,r=n;
	while(l<r)
	{
		long long mid=(l+r+1)/2;
		if(check(mid))
		{
			l=mid;
		}
		else
		{
			r=mid-1;
		}
	}
	printf("%lld",l);
	return 0;
} 
