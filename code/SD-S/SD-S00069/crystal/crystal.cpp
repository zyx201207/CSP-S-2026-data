#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m;
int a[500005];
int b[500005], ans;
int pref[500005];

int sum(int l, int r)
{
	int ans = 0;
	for(int i = l;i < r;i++)
		ans += a[r] - a[i];
	return ans;
}

signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	sort(a + 1,a + 1 + n);
//	for(int i = 1;i <= n;i++)
//		b[i] = a[i] - a[i - 1], pref[i] = pref[i - 1] + b[i];
	int i = 1, j = 2;
	ans = 1;
	while(i < j && i <= n && j <= n)
	{
		if(sum(i, j) <= m)
		{
			ans = max(ans, j - i + 1);
			j++;
		}
		else
			i++;
	}
	cout << ans;
	
	return 0;
}
