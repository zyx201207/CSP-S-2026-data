#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n,m;
long long a[500005],b[500005],ans=1;
bool cmp(long long x,long long y)
{
	return x>y;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	long long l=1,r=1;
	b[0]=0;
	for(int i=1;i<=n;i++)
	{
		b[i]=b[i-1]+a[i];
	}
	for(;l<=n;l++)
	{
		r=max(l,r);
		long long sum1=(b[r]-b[l-1]);
		long long sum=(r-l+1)*a[l]-sum1;
		long long cnt=r-l+1;
		while(r+1<=n&&sum+(a[l]-a[r+1])<=m)
		{
			r++;
			sum+=a[l]-a[r];
			cnt++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans<<endl;
	return 0;
}
