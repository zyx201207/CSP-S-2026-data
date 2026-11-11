#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

const int N=5e5+20;
long long a[N];
long long n,m;
int er(int b)
{
	long long mm=m;
	for(int i=0;i<=n-1;i++)
		if(a[i]<b)
			mm=mm-(b-a[i]);
	return mm;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=0;i<=n-1;i++)
		scanf("%lld",&a[i]);
	sort(a,a+n);
	long long l=a[0],r=a[n-1],mid;
	while(l<r)
	{
		mid=(long long)(l+r)/2+1;
		if(er(mid)>0)
			l=mid+1;
		else
			r=mid-1;
	}
	long long num=0;
	for(int i=0;i<=n-1;i++)
		if(a[i]<=l)
			num++;
	printf("%lld",num);
	return 0;
}
