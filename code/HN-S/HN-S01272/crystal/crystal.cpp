#include <bits/stdc++.h> 
#define int long long

using namespace std;

const int N = 5e5 + 100;

int n, m;
int a[N];
int sum[N];

bool check(int mid) 
{
	for (int i = mid; i <= n; i++) 
	{
		if (a[i] * mid - (sum[i] - sum[i - mid]) <= m) return true;
	}
	return false;
}

signed main () 
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	sort (a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	
	int l = 1, r = n;
	int ans = 1;
	
	while (l <= r) 
	{
		int mid = (l + r) / 2;
		if (check(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	
	printf("%lld\n", ans);
	return 0;
} 
