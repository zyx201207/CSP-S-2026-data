#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 5;
ll a[maxn];
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	ll m;
	scanf("%d%lld", &n, &m);
	for(int i = 1; i <= n; i++)scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	int l = 1, r, ans = 0;
	ll sum = 0;
	for(r = 2; r <= n; r++)
	{
		if(a[r] != a[r - 1])sum += (a[r] - a[r - 1]) * (r - l);
		while(sum > m)
		{
			sum -= a[r] - a[l];
			l++;
		}
		ans = max(ans, r - l + 1);
	}
	printf("%d\n", ans);
	return 0;
}
