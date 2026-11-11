#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
int n;
long long m;
long long a[N],s[N];
int ans;
int maxn = -0x3f;
int srcmin = 0;
int solveA()
{
	int cntA = 0;
	for (int i = n;i >= 1;i--)
	{
		if (m >= s[i])
		{
			cntA++;
			m -= s[i];
		}
	}
	return cntA;
}
int solveB()
{
	int cntB = 0;
	for (int i = n;i >= 1;i--)
	{
		if (m >= s[i])
		{
			cntB++;
			m -= s[i];
		}
	}
	return cntB;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	bool flagA = true;
	bool flagB = true;
	for (int i = 1;i <= n;i++)
	{
		if (a[i] != i)
		{
			flagA = false;
		}
		if (i != n && i != 1 && a[i + 1] - a[i] != a[i] - a[i - 1])
		{
			flagB = false;
		}
	}
	sort(a + 1,a + n + 1);
	for (int i = 1;i <= n;i++)
	{
		s[i] = a[n] - a[i];
	}
	if (flagA)
	{
		cout << solveA();
		return 0;
	}
	if (flagB)
	{
		cout << solveB();
		return 0;
	}
	for (int pos = n;pos >= srcmin;pos--)
	{
		ans = 0;
		for (int i = 1;i <= pos;i++)
		{
			s[i] = a[pos] - a[i];
		}
		for (int i = n;i >= 1;i--)
		{
			if (m >= s[i])
			{
				m -= s[i];
				ans++;
			}
		}
		if (ans > maxn)
		{
			maxn = ans;
			srcmin = ans + 1;
		}
	}
	cout << maxn;
	return 0;
}
