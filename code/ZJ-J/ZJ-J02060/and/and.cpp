#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e5 + 10;
int n, m;
int ans, cnt;
int a[N];

void dfs(int num, int cnt, int x)
{
	if(num == m)
	{
		ans = max(ans, cnt);
		return;
	}
	
	for(int i = x + 1; i <= n; i ++)
		dfs(num + 1, (cnt & a[i]), i);
}
signed main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	scanf("%d %d", &n, &m);
	scanf("%d", &a[1]);
	int t = INT_MAX;
	bool checkA = true, checkB = true;
	cnt = a[1];
	
	if(a[1] & t != a[1]) checkA = false;
	int k = log2(n);
	if(a[1] || (1 << k) != n) checkB = false;
	 
	for(int i = 2; i <= n; i ++)
	{
		scanf("%d", &a[i]), cnt = cnt & a[i];
		if(a[i] & t != a[i]) checkA = false;
		if(a[i] != i - 1) checkB = false;
	}
		
	if(checkA)
	{
		sort(a + 1, a + 1 + n, greater<int>());
		printf("%lld\n", a[m]);
		return 0;
	}
	if(checkB)
	{
		sort(a + 1, a + 1 + n, greater<int>());
		int x = a[1];
		for(int i = 2; i <= m; i ++) x = x & a[i];
		printf("%lld\n", x);
		return 0;
	}
	if(m == n)
	{
		printf("%d\n", cnt);
		return 0;
	}
	sort(a + 1, a + 1 + n);
	ans = -1e18;
	
	if(m == 1) printf("%d\n", a[n]);
	else
		for(int i = 1; i <= n; i ++)
			dfs(1, a[i], i);
	
	printf("%d\n", ans);
	return 0;
}
