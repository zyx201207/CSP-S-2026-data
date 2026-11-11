#include<bits/stdc++.h>
#define N 500005
using namespace std;
long long a[N],m,sum,t;
int n,l,r,mid;
bool f;
bool check(int d)
{
	f=false;
	sum=0;
	for(int i=1;i<d;++i)
		sum=(long long)sum+a[i];
	for(int i=d;i<=n;++i)
	{
		sum=(long long)sum+a[i]-a[i-d];
		t=(long long)a[i]*d-sum;
		if(t<=m)
		{
			f=true;
			break;
		}
	}
	return f;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;++i)scanf("%lld",a+i);
	sort(a+1,a+1+n);
	l=1,r=n;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(check(mid))
			l=mid+1;else
			r=mid;
	}
	if(!check(l))
		--l;
	printf("%d",l);
	return 0;
}