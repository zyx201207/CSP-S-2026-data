#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>


using namespace std;

const int N=5e5+100;

int n;
long long m;
long long a[N];
long long A[N];

bool cmp(long long a,long long b)
{
	return a<b;
}

bool check(int len)
{
	long long minm=m+1;
	if(A[len]<minm)
	{
		return true;
	}
	for(int i=len+1;i<=n;i++)
	{
		long long newm=A[i]-A[i-len]-(i-len)*(a[i]-a[i-len]);
		if(newm<minm)
		{
			return true;
		}
	}
	return false;
}


int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	if(n==1)
	{
		printf("1\n");
		return 0;
	}
	for(int i=1;i<=n;i++)
		scanf("%lld",a+i);
	sort(a+1,a+n+1,cmp);
	for(int i=2;i<=n;i++)
	{

		A[i]=A[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	if(A[n]<=m)
	{
		printf("%d\n",n);
		return 0;
	}
	int l=1,r=n;
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		if(check(mid))
		{
			l=mid;
		}
		else
		{
			r=mid-1;
		}
	}
	printf("%d\n",l);
	return 0;
}
