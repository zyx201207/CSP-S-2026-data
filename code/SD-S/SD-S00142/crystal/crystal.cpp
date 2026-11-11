#include <iostream>
#include <algorithm>
#include <cstdio>
#define ll long long
using namespace std;
const int MAXN = 5e5 + 5;
int n;
ll m, a[MAXN], pre[MAXN];
bool check(int ans)
{
	for(int i = ans; i <= n; i++)
	{
		ll ls1 = pre[i] - pre[i - ans];
		ll ls2 = a[i] * ans;
		if(ls2 - ls1 <= m)
		{
			return true;
		}
	}
	return false;
}
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)
	{
		pre[i] = pre[i - 1] + a[i];
	}
	int l = 1, r = n, ans = 1;
	while(l <= r)
	{
		int mid = (l + r + 1) >> 1;
		if(check(mid))
		{
			l = mid + 1;
			ans = mid;
		}
		else
		{
			r = mid - 1;
		}
	}
	printf("%d", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
// 14:42 今年怎么这么水 
// 14:53 对拍拍出错来了，不水了
// 14:56 暴力出错了没绷住 T1 AC.
