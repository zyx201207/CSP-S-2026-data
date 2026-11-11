#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 5e5+5;
int n;
ll m;
ll a[MAXN];
bool cmp(int x, int y)
{
	return x < y;
}
int main()
{
	cin.tie(0)->ios::sync_with_stdio(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	int l = 1, r = n;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		ll c = 0, ans = 0;
		for (int i = 1; i <= mid; i++)
		{
			c += a[i];
		}
		c += m;
		double t = c * 1.0 / mid;
		c /= mid;
		for (int i = 1; i <= mid; i++)
		{
			ans += abs(a[i] - c);
		}
		if (ans > m)
		{
			r--;
		}
		if (ans < m)
		{
			l++;
		}
		if (t - long(t) > 1e-9)
		{
			continue;
		}
		if (ans == m)
		{
			int temp = mid;
			for (int i = mid + 1;; i++)
			{
				if (a[i] == a[mid])
				{
					temp++;
				}
				else
				{
					break;
				}
			}
			cout << temp;
			return 0;
		}
	}
	return 0;
}