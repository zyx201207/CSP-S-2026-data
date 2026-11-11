#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5+5;
int n,m,a[MAXN],f[MAXN],sum[MAXN];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		f[i]=a[i]-a[i-1];
		sum[i]=sum[i-1]+f[i];
	}
	int maxv=0;
	for(int l=1;l<=n;l++)
		for(int r=l;r<=n;r++)
			if(sum[r]-sum[l-1]<=m)
				maxv=max(maxv,r-l+1);
	cout<<maxv;
	return 0;
}
