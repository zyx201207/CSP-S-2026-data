#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, l, r, now, m, ans;
const int N = 5e5 + 10;
int a[N];
signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	// for(int i = 1; i <= n; i++) cout << a[i] << " ";
	// cout << "\n";
	l = 1, r = 2, now = 0, ans = 1;
	for(;r <= n; r++)
	{
		now += (r - l) * (a[r] - a[r - 1]);
		if(now <= m)
		{
			ans = max(ans, (r - l + 1));
		}
		else
		{
			//cout << "xing";
			while(now > m && l < r)
			{
				//cout << "xing";
				now -= (a[r] - a[l]);
				l++;
			}
			ans = max(ans, (r - l + 1));
		}
		//cout << l << " " << r << " " << ans << " " << now << "\n";
	}
	cout << ans;
}