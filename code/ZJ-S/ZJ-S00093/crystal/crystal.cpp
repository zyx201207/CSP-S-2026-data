#include <algorithm>
#include <cstdio>

typedef long long int ll;
constexpr int N = 5e5 + 5;

ll n, m, ans, a[N], s[N];

int main(void)
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	scanf("%lld %lld", &n, &m);
	
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	
	std::sort(a + 1, a + 1 + n);
	
	for (int i = 1; i <= n; i++)
	{
		s[i] = s[i - 1] + a[i];
		
		ll l = 1, r = i;
		
		while (l < r)
		{
			ll mid = (l + r) >> 1;
			
			if (a[i] * (i - mid + 1) - (s[i] - s[mid - 1]) <= m) r = mid;
			else l = mid + 1;
		}
		
		ans = std::max(ans, i - l + 1);
	}
	
	printf("%lld", ans);
	
	#define _ 0
	return ~~(0^_^0);
	#undef _
}

