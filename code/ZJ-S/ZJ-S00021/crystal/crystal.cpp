#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500009] = {0};
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld", &n, &m);
	for(int i = 1; i<=n; ++i) scanf("%lld", &a[i]);
	sort(a+1,a+n+1);
	int ans = 1;
	int k = 1;
	int w = 0;
	for(int i = 2; i<=n; ++i)
	{
		w+=(a[i]-a[i-1])*(i-k);
		while(w>m)
		{
			w-=(a[i]-a[k]);
			k++;
		}
		ans=max(ans,i-k+1);
	}
	printf("%lld\n", ans);
	return 0;
}
