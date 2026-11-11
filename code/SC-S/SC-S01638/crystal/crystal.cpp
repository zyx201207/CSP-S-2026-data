#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
long long a[10000001];
long long ans=0;
long long sum[5000001];
long long m;
int n;
long long c=0;
void f(int k)
{
	long long p=0,l=k+m-1;
	if(k==n) return ;
	if(k+m-1>=n)
	{
		l=n-1;
	}
	for(int i=k;i<=l;++i)
	{
	    ans=a[i+1]-a[i];
	    p+=ans*i;
		if(p<=m)
		{
			sum[k]++;
		}
	}
	c=max(sum[k]+1,c);
	f(k+1);
	return ;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    scanf("%d %lld",&n,&m);
//    for(int i=1;i<=n;++i)
//    {
//    	sum[i]=1;
//	}
    for(int i=1;i<=n;++i)
    {
    	scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	f(1);
	printf("%lld",c);
	return 0;
}
