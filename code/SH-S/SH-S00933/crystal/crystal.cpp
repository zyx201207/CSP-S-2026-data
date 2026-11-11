#include <bits/stdc++.h>

using namespace std;

int n, ans = 0, temp = 0;
long long m, a[10000], j, x;

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	x = m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 1; i < n; i++)
	{
		temp = 0, j = i, m = x;
		while (m >= 0 && j >= 0)
		{
			m = m - (a[i] - a[j]); 
			temp++;
			j--;
		}
		if (temp > ans)
		{
			ans = temp; 
		}
	}
	cout << ans;
	return 0;
 } 
