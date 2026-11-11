#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define int long long

const int N = 5e5 + 10;

int n, m;
int a[N], sum[N] = {};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; i ++ )
		cin >> a[i];
		 
	sort(a + 1, a + n + 1);
	
	for (int i = 1; i <= n; i ++ )
		sum[i] = sum[i - 1] + a[i];
	
	int ans = 0;
	for (int i = 1; i <= n; i ++ )
	{
		int l = 1, r = i;
		while ( l <= r )
		{
			int mid = (l + r) >> 1;
			if ( (i - mid + 1) * a[i] - (sum[i] - sum[mid - 1]) <= m ) ans = max(ans, i - mid + 1), r = mid - 1;
			else l = mid + 1;
		}
	}
	
	cout << ans;
	return 0;
}
