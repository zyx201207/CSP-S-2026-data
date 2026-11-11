#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 5e5 + 10, M = 3e7 + 10;
int n, m;
int ans;
int a[N], s[N];
int f[M];

signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	bool checkA = true;
	scanf("%lld %lld", &n, &m);
	for(int i = 1; i <= n; i ++)
	{
		scanf("%lld", &a[i]);
		if(a[i] != i) checkA = false;
	}
 			
	if(checkA)
	{
		for(int i = 1; i <= n; i ++)
		{
			ans ++;
			if(m < a[i]) 
				break;
			m = m - a[i];
		}
		if(ans > n) ans = n;
		printf("%lld\n", ans);
		return 0;		
	}
			
 	sort(a + 1, a + 1 + n);
			
	memset(f, -0x3f, sizeof f);
	
	for(int i = 1; i <= m; i ++) f[i] = 0;
	
	m ++;
	for(int i = 1; i < n; i ++)
		for(int k = i + 1; k <= n; k ++)
			for(int j = m; j >= a[k] - a[i]; j --)
			{
				if(m - a[k] + a[i] < 0) continue;
				f[j] = max(f[j], f[j - a[k] + a[i]] + 1);
			}
	int ans = -1e9;
	for(int i = 1; i <= m; i ++)
		ans = max(ans, f[i]);
		
	if(ans > n) ans = n;
	printf("%lld\n", ans);
	return 0;
} 
