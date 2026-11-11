#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, ans;
pair<int, char> p, a[200005];
signed main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	int l = 1, r = n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i].first >> a[i].second;
	}
	while(l < r)
	{
		if(a[l].second != a[r].second)
		{
			if(a[l].first == a[r].first)
				ans += a[l].first, l++, r--;
			else if(a[l].first > a[r].first)
				ans += a[r].first, a[l].first -= a[r].first, r--;
			else
				ans += a[l].first, a[r].first -= a[l].first, l++;
		}
		else
		{
			if(a[l].first == a[r].first)
				l++, r--;
			else if(a[l].first > a[r].first)
				a[l].first -= a[r].first, r--;
			else
				a[r].first -= a[l].first, l++;
		}
	}
	cout << ans << '\n';
	return 0;
}
