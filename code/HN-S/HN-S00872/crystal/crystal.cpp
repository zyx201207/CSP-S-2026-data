#include <bits/stdc++.h>
using namespace std;

int n;
long long m, a[500005];

bool check(int len)
{
	long long sum = 0;
	for(int i = 1; i <= len - 1; i ++)
	{
		sum += a[len] - a[i];
	}
	if(sum <= m)
	{
		return true;
	}
	for(int i = len + 1; i <= n; i ++)
	{
		sum += (len - 1) * (a[i] - a[i - 1]);
		sum -= a[i - 1] - a[i - len];
		if(sum <= m)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int l = 1, r = n;
	for(; l < r; )
	{
		int mid = (l + r + 1) / 2;
		if(check(mid) == true)
		{
			l = mid;
		}
		else
		{
			r = mid - 1;
		}
	}
	cout << l << '\n';
	return 0;
}
