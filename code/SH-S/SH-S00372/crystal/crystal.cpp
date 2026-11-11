#include <bits/stdc++.h>
using namespace std;
int n,ans;
long long m, a[500100],b[500100];
bool judge(int x, int y)
{
	for(int i = 0;i <= n - x;i++)
	{
		if(x * a[i + x] - (b[i + x] - b[i]) <= m)
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
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	int cnt = 0;
	for(int i = n;i >= 1;i--)
	{
		a[i] -= a[1];
	}
	for(int i = 1;i <= n;i++)
	{
		b[i] = b[i - 1] + a[i];
	}
	int l = 1,r = n;
	while(l < r)
	{
		int mid = (l + r) / 2;
		if(judge(mid,m))
		{
			l = mid + 1;
			ans = mid;
		}
		else
		{
			r = mid;
		}
	}
	cout << ans;
	return 0;
}
