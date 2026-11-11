#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=500005;
ll a[N],s[N],m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,i,j,l,r,mid,ans=0;
	scanf("%d%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
	}
	for(i=1;i<=n;i=j+1)
	{
		j=i+1;
		while(j<=n&&a[j]==a[i])
		{
			j++;
		}
		j--;
//		s[i]-s[k-1]+m>=(i-k+1)*a[i]
//		s[i]+m-(i+1)*a[i]>=s[k-1]-k*a[i]
		l=1;
		r=i;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(s[i]-s[mid-1]+m>=(i-mid+1)*1ll*a[i])
			{
				r=mid;
			}
			else
			{
				l=mid+1;
			}
		}
		ans=max(ans,j-l+1);
	}
	printf("%d",ans);
	return 0;
}
