#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int N=5e5+5;
long long a[N],sum[N];
long long n,m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)
	{
		sum[i]=sum[i-1]+a[i];
		
	}
	int l=1,r=n,ans;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		int flag=1;
		for(int i=1;i+mid-1<=n;++i)
		{
			int j=i+mid-1;
			if((a[j]*mid-sum[j]+sum[i-1])<=m)
			{
				ans=mid;
				l=mid+1;
				flag=0;
				break;
			}
		}
		if(flag==1) r=mid-1;
	}
	cout<<ans;
	return 0;
}
