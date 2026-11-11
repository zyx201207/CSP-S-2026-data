#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
int n , ans = 1 , l , r;
ll m , a[N] , pre[N] , tot;
int main()
{
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1;i <= n;i ++) cin >> a[i];
	sort(a + 1 , a + 1 + n);
	for (int i = 1;i <= n;i ++) pre[i] = pre[i - 1] + a[i];
	for (int i = 2;i <= n;i ++)
	{
		if  (m >= a[i] * (i - 1) - pre[i - 1]) ans = max(ans , i);
		else
		{
			l = 1 , r = i - 1;
			while (l < r)
			{
				int mid = l + r >> 1;
				if  (a[i] * (i - mid) - pre[i - 1] + pre[mid - 1] <= m) r = mid;
				else l = mid + 1; 
			}
			ans = max(ans , i - l + 1);
		}
	}
	cout << ans;
	return 0;
} 
