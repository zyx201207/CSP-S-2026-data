#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],sum[500005],ans;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",a+i);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1,p=1;i<=n;i++)
	{
		while((i-p+1)*a[i]-(sum[i]-sum[p-1])>m) p++;
		ans=max(ans,i-p+1);
	}
	printf("%lld\n",ans);
	return 0;
}