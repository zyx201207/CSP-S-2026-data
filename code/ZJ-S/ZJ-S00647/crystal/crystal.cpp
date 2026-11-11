#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m;
long long a[N],s[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	int res=0;
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
		int l=1,r=i;
		int ans=0;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if((i-mid+1)*a[i]-(s[i]-s[mid-1])<=m)
			{
				ans=mid;
				r=mid-1;
			}
			else l=mid+1;
		}
		res=max(res,i-ans+1);
	}
	printf("%lld",res);
	return 0;
}