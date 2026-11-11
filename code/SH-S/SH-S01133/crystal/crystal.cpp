#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+5;
long long n,m,a[N],b[N],c[N],d[N];
int main()
{
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
scanf("%lld%lld",&n,&m);
for(long long i=1;i<=n;i++)
	scanf("%lld",&a[i]);
sort(a+1,a+n+1);
long long sum=1,pj=0;
for(long long r=1,l=1;r<=n;r++)
{
	pj+=a[r];
	long long q=a[r]*(r-l+1);
	while(q-pj>m)
	{
		pj-=a[l];
		l++;
		q-=a[r];
		
	}
	sum=max(sum,r-l+1);
}
	printf("%lld",sum);	
return 0;
	
}

