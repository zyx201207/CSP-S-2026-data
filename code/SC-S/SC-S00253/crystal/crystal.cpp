#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5 * 1e5 + 5;
int n, m, ans;
int a[N];
int nair(int p)
{
	int ret = 0, i = p, now = 0;
	while(i >= 1)
	{
		if(now + a[p] - a[i] > m) break;
		now += a[p] - a[i];
		ret++, i--;
	}
	return ret;
}
signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	if(n > 5000)
	{
		int s = 0, x = 0, tp, gc;
		bool f = 0;
		for(int i = 1; i <= n; i += gc)
		{
			tp = x;
			cin >> x;
			gc = x - tp;
			if(s + x <= m) s += x;
			else if(!f)
			{
				ans = i;
				f = 1;
			}
			if(i == n)
				ans = n;
		}
		cout << ans;
		return 0;
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a+1, a+1+n);
	for(int i = 2; i <= n; i++)
	{
		ans = max(ans, nair(i));
	}
	cout << ans;
	return 0;
}