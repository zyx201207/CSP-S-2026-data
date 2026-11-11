#include<bits/stdc++.h>
using namespace std;
long long m;
int n;
const int N=500005;
long long a[N];
int mx=-1;
int myjian(long long a,long long b)
{
	if(a>=0&&b>=0)return a-b;
	if(a>=0&&b<0)
	{
		return a+(-b);
	}
	return abs((-a)-(-b));
}
void solve1()
{
	
	for(int i=2;i<=n;i++)
	{
		long long k=m;
		int j=i-1,cnt=0;
		while(k>=0)
		{
			long long kk=myjian(a[i],a[j]);
			k-=kk;
//			cout<<i<<": "<<kk<<"\n";
			if(k>=0)
			{
				mx=max(++cnt,mx);
			}
			if(j>1)j--;
			else break;
		}
	}
	printf("%d",mx+1);
}
int check(long long u,long long z)
{
	long long p=u*(u-1)/2;
//	cout<<u<<" "<<p<<"\n";
	if(p<=z)return 1;
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);	
	}
	sort(a+1,a+1+n);
	if(n<=10000)
	{
		solve1();
		return 0;
	}
	long long g=a[2]-a[1];
	long long h=m/g;
	long long l=1,r=n;
	while(l<=r)
	{
		long long mid=(l+r)>>1;
		if(check(mid,h))
		{
			l=mid+1;
		}else
		{
			r=mid-1;
		}
	}
	printf("%lld",l-1);
	return 0;
}