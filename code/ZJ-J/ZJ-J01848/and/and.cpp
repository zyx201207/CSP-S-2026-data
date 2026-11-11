#include <bits/stdc++.h>
using namespace std;
long long n, m, ans;
int a[201020];
int b[50];
long long c[50];
bool d[48];
int f[200010];
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	c[0] = 1;
	for (int i = 1; i <= 32; i++) c[i] = c[i - 1] * 2;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		int x = a[i];
		for (int j = 32; j >= 0; j--)
		{
			if (x >= c[j]) 
			{
				b[j]++;
				x -= c[j];
			}
		}
	}
	int k = 0;
	for (int i = 0; i <= 32; i++) if (b[i] >= m) k = i;
	memset(b, 0, sizeof(b));
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		int flag = 0;
		int x = a[i];
		for (int j = 32; j >= 0; j--)
		{
			if (x >= c[j]) 
			{
				x -= c[j];
				if (j == k) 
				{
					flag = 1;
					cnt++;	
				}
				if (flag) 
				{
					b[j]++;
					f[cnt] += c[j];
				}
			}
		}
	}
	for (int i = 0; i <= k; i++) if (b[i] >= m) d[i] = 1;
	for (int i = 0; i <= k; i++)
	{
		if (d[i]) ans += c[i];
	}
	cout << ans << endl;
	return 0;
}