#include <iostream>
using namespace std;
long long b[50005],c[30005];
int main()
{
	int n,m;
	long long a[50005];
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[n];
	}	
	for (int y = 1; y <= m; y++)
	{
		for (int j = y; j <= m; j++)
		{
			b[j] = a[j];
			for (int h = y - 1; h < j; h++)
			{
				if (b[h] == a[j])
				{
					for (int x = h; x < j; x++)
					{
						b[x] = 0;
					}
				}
			}
		}
		for (int z = 1; z <= m; z++)
		{
			for (int p = 1; p <= n; p++)
			{
				if (b[p] == z)
				{
					c[z] ++;
				}
			}
		}
		for (int k = 0; k <= n; k++)
		{
			b[k] = 0;
		}
	}
	for (int u = 1; u <= m; u++)
	{
		cout << c[u] << " ";
	}
	return 0;
}