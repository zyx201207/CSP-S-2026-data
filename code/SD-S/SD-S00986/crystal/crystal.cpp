#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
int n,ans;
ll m,a[N],sumzheng[N],sumfu[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i = 1;i <= n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a + 1,a + 1 + n);
	for(int i = 1;i <= n;i++)
	{
		sumzheng[i] = sumzheng[i - 1];
		sumfu[i] = sumfu[i - 1];
		if(a[i] >= 0)
		{
			sumzheng[i] += a[i];
		}
		else
		{
			sumfu[i] += a[i];
		}
	}
	int l,r;
	for(int i = 1;i <= n;i++)
	{
		l = 1,r = i;
		while(l <= r)
		{
			int mid = (l + r) >> 1;
			if(a[i] * (1ll * i - 1ll * mid) - sumzheng[i - 1] - sumfu[i - 1] + sumzheng[mid - 1] + sumfu[mid - 1] <= m)
			{
				ans = max(ans,i - mid + 1);
				r = mid - 1;
			}
			else
			{
				l = mid + 1;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
