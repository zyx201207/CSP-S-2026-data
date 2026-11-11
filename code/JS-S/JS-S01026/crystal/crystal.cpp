#include <bits/stdc++.h>
using namespace std;
long long a[500005];
long long n, m;
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for(int j = 1; j <= 2000000; j++)
	{
		if(j * (j + 1) >= 2 * m)
		{
			cout << j;
			break;
		}
	}
	return 0;
}

