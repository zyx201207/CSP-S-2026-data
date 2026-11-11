#include <bits/stdc++.h>
using namespace std;
long long n,l,r,a[200010],ans;
char c[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++)scanf("%lld %c",&a[i],&c[i]);
	l=1,r=n;
	while(l<r)
	{
		if(a[l]==a[r])
		{
			if(c[l]==c[r])
			{
				l++,r--;
			}
			else
			{
				ans+=a[l];
				l++,r--;
			}
		}
		else if(a[l]<a[r])
		{
			if(c[l]==c[r])
			{
				a[r]-=a[l],l++;
			}
			else
			{
				ans+=a[l];
				a[r]-=a[l],l++;
			}
		}
		else
		{
			if(c[l]==c[r])
			{
				a[l]-=a[r],r--;
			}
			else
			{
				ans+=a[r];
				a[l]-=a[r],r--;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}