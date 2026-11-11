#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

const int N = 5e5 + 10;

ll n, m;
ll a[N];

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	
	ll targ, req = 0; // target  requirement
	ll ans = 1;
	for (int r = 1, l = 1; r <= n; ++r)
	{
		targ = a[r];
		ll diff = a[r] - a[r - 1];
		ll len = r - l + 1;
		req += diff * (len - 1);
		while (req > m)
		{
			req -= targ - a[l];
			l++;
		}
		len = r - l + 1;
		ans = max(ans, len);
	}
	cout << ans;
	return 0;
}
 
