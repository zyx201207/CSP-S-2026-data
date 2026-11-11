#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

#define int long long
#define f(x) freopen(#x".in", "r", stdin), freopen(#x".out", "w", stdout);

const int N = 2e6 + 5;

int C, T, n, d, ans;
int a[N];
bool core[N];

bool isCore(int x, int y, int z)
{
	return x <= d && y <= d && z <= d && x + y <= d && y + z <= d && x + y + z > d;
}

signed main()
{
	f(migrate);
	scanf("%lld%lld", &C, &T);
	
	while (T --)
	{
		ans = 0;
		memset(core, 0, sizeof core);
		scanf("%lld%lld", &n, &d);
		
		for (int i = 0; i < n; ++ i)
		{
			scanf("%lld", a + i);
		}
		for (int i = n - 1; i > 0; -- i) 
		{
			a[i] -= a[i - 1];
		}
		a[0] = 0;
		
		// (1) ~ (n - 1)
		
		for (int i = 1; i <= n - 3; ++ i)
		{
			int x = a[i], y = a[i + 1], z = a[i + 2];
			core[i] = isCore(x, y, z);
			if (!core[i]) continue;
//			printf("%d", (int)core[i]);

			int l = i - 1, r = i + 3;
			while (l >= 1 && a[l] <= d && a[l] + a[l + 1] > d) l --;
			while (r <= n && a[r] <= d && a[r] + a[r - 1] > d) r ++;
			
			l = i - l, r = r - (i + 2);
			ans += l * r;
		}
//		puts("");
		printf("%lld\n", ans);
	}
	
	return 0;
}