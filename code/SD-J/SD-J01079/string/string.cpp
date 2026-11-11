#include <iostream>
using namespace std;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, i = 0, cnt = 0;
	cin >> n;
	long long a[100000000];
	char c[100000];
	while(cin >> a[i] >> c[i])
	{
		i++;
	}
	for(int j = 1; j <= n; j++)
	{
		if(a[n - j - 1] != 0)
		{
			for(int q = 1; q <= n; q++)
			{
				if(a[q] != 0)
				{
					if(c[j] == c[n - j - 1])
					{
						if(a[j] > a[n - j - 1])
						{
							a[j] -= a[n - j - 1];
							a[n - j - 1] = 0;
						}else if(a[j] == a[n - j - 1])
						{
							a[j] = 0;
							a[n - j - 1] = 0;
						}else if(a[j] < a[n - j - 1])
						{
							a[n - j - 1]  -= a[j];
							a[j] = 0;
						}
					}else if(c[j] != c[n - j - 1])
					{
						if(a[j] > a[n - j - 1])
						{
							cnt += a[n - j - 1];
							a[j] -= a[n - j - 1];
							a[n - j - 1] = 0;
						}else if(a[j] == a[n - j - 1])
						{
							cnt += a[j];
							a[j] = 0;
							a[n - j - 1] = 0;
						}else if(a[j] < a[n - j - 1])
						{
							cnt += a[j];
							a[n - j - 1]  -= a[j];
							a[j] = 0;
						}
					}
				}
			}
		}
	}
	cout << cnt;
	return 0; 
}
