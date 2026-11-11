//A,B特殊情况 其他错误做法 
#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],c[500005],ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	b[1] = 0;
	for (int i = 2;i <= n;i++)
	{
		b[i] = (i - 1) * (a[i] - a[i - 1]) + b[i - 1];
	}
	c[n] == 0;
	for (int i = n - 1;i >= 1;i--)
	{
		if (b[i + 1] == b[i])
		{
			c[i] = c[i + 1] + 1;
		}
	}
	bool f = 0;
	for (int i = 1;i <= n;i++)
	{
		if (m == b[i])
		{
			ans = i + c[i];
			f = 1;
			break;
		}
		else if (m < b[i])
		{
			ans = i - 1 + c[i - 1];
			f = 1;
			break;
		}
	}
	if (f == 0)
	{
		cout << n;
	}
	for (int i = 1;i <= n;i++)
	{
		ans = max(ans,c[i]);
	}
	cout << ans;
	return 0;
}
