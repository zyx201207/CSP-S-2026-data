#include <iostream>
#include <algorithm>
using namespace std;

int a[500010];
__int128 pre[500010], target[500010];

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int maxn = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		maxn = max(maxn, abs(a[i]));
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)
	{
		pre[i] = pre[i - 1] + a[i];
		target[i] = 1ll * a[i] * i - pre[i];
		//cout << pre[i] << endl;
	}
	for(int i = 1; i <= n; i++)
	{
		pre[i] = pre[i - 1] + a[i];
		target[i] = 1ll * a[i] * i - pre[i];
		//cout << pre[i] << endl;
	}
	int ans = 0, l = 1, r = 1;
	for(int i = 1; i <= n; i++)
	{
		//cout << target[l] << endl;
		while(target[r] - (a[i] * l - pre[l]) <= m && r < n)
		{
			r++;
		}
		ans = max(ans, r - l);
		l++;
		//cout << l << " " << r << endl;
	}
	cout << ans << endl;
	return 0;
}
