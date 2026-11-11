#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	long long max = 0, n, m, a[5000];
	cin >> n, m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			if (a[j] and a[i] > max) max = a[j] and a[i];
		}
	}
	cout << max;
	return 0;
}