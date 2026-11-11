#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int a [N];
signed main ()
{
	ios::sync_with_stdio(false);cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i ++) cin >> a [i];
	sort (a + 1,a + n + 1);
	a [n + 1] = a [n];
	int l = n,ans = 1,sum = 0;
	for (int r = n;r >= 1;r --)
	{
		sum -= (a [r + 1] - a [r]) * (r - l + 1);
		while (sum + a [r] - a [l - 1] <= m && l >= 2)
		{
			sum += a [r] - a [l - 1];
			l --;
		}
		ans = max (ans,r - l + 1);
	}
	cout << ans;
	return 0;
}