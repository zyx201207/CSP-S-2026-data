#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n,ans;
long long m,a[N],qzh[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i = 1;i <= n;i++) scanf("%lld",&a[i]);
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++) qzh[i] = qzh[i - 1] + a[i];
	for(int i = 1;i <= n;i++)
	{
		int l = 1,r = i,mid;
		while(l < r)
		{
			mid = (l + r) >> 1;
			if((i - mid + 1) * a[i] - (qzh[i] - qzh[mid - 1]) <= m) r = mid;
			else l = mid + 1;
		}
		ans = max(ans,i - r + 1);
	}
	printf("%d",ans);
	return 0;
} 
