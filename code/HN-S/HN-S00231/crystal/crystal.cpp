#include<bits/stdc++.h>
using namespace std;
#define int long long
int n , m , ans = 0;
int a[500005] , p[500005];
signed main()
{
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)cin >> a[i];
	sort(a + 1 , a + 1 + n);
	p[0] = 0;
	for(int i = 1; i <= n; i ++)p[i] = p[i - 1] + a[i];
	for(int i = 1; i <= n; i ++)
	{
		int l = 1 , r = i;
		while(l < r)
		{
			int mid = (l + r) >> 1;
			if((i - mid) * a[i] - (p[i - 1] - p[mid - 1]) > m)l = mid + 1;
			else r = mid;
		}
		ans = max(ans , i - l + 1);
	}
	cout << ans;
	return 0;
}
