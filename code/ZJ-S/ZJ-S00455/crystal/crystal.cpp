#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int n,ans = 1;
long long m,sum,a[500010];

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for (int i = 1;i <= n;i++) scanf("%lld",&a[i]);
	sort(a + 1,a + n + 1);
	for (int i = 1,j = 1;i <= n;) 
	{
		while (j < n && sum + (a[j + 1] - a[j]) * (j - i + 1) <= m) sum += (a[j + 1] - a[j]) * (j - i + 1),j++;
		ans = max(ans,j - i + 1),sum -= a[j] - a[i++];
		if (i > j) j = i;
	}
	printf("%d\n",ans);
	return 0;
}
