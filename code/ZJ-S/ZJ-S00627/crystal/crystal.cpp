#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n;
long long m;
long long a[N];
long long sum[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i = 1;i <= n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++) sum[i] = sum[i - 1] + a[i];
	int res = 0;
	for(int i = 1;i <= n;i++)
	{
		int l = 1,r = i,mid,best = i;
		while(l <= r)
		{
			mid = (l + r) / 2;
			long long tmp = a[i] * ((long long)(i - mid + 1));
			tmp = tmp - sum[i] + sum[mid - 1];
			if(tmp <= m)
			{
				best = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		res = max(res,i - best + 1);
	}
	printf("%d",res);
	return 0;
}
