#include <bits/stdc++.h>
using namespace std;
int n, m, a[1000005], f[1000005];
bool cmp(int x, int y) 
{
	return x > y;
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int c = 0;
	sort(a + 1, a + n + 1, cmp);
	f[1] = a[1];
	for(int i = 2; i <= n; i++)
	{
		if (c >= m) break;
		else
		{
			if(a[i] & f[i - 1] > f[i - 1])
			{
				f[i] = a[i] & f[i - 1];
				c++;
			}				
			else
			{
				f[i] = f[i - 1];
			}
		}
	}
	cout << f[n];
	return 0;
}
