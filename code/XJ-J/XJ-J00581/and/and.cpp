#include <iostream>
using namespace std;
int main()
{
	int n,m;
	long long a[20005];
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	long long b[20005];
	for (int j = 0; j < n; j++)
	{
		for (int x = 1; x <= n; x ++)
		{
			b[j * n + x] = a[j + 1] ^ a[x + j + 1];
		}
	}
	int sum = 0,maxxx = 0;
	int laoda = ((n * (n - 1))/ 2);
	for (int y = 1; y <= m; y++)
	{
		for (int z = 1; z <= laoda; z ++)
		{
			if (b[z] > maxxx)
			{
				maxxx = b[z];
			}
		}
		for (int t = 1; t <= laoda; t++)
		{
			if (b[t] == maxxx)
			{
				b[t] = 0;
				break;
			}
		}
		sum += maxxx;
		maxxx = 0;
	}
	cout << sum;
	return 0;
}