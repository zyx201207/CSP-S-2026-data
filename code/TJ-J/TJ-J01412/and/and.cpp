#include<bits/stdc++.h>
using namespace std;
long long n,m, a[200005], maxn = -1, x, b[200005];
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	x = a[0];
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < m; k++)
		{
			for (int j = i + 1; j < n; j++)
			{
				b[i] = a[i] & a[j];
			}
		}
		if (maxn < b[i]) maxn = b[i];
	}
	cout << maxn;
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
