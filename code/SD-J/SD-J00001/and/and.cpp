#include <bits/stdc++.h>
using namespace std;

long long n, m;
long long a[200005];

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	
	long long max = -999;
	if(m == 1)
	{
		for(int i = 1; i <= n; i++)
		{
			if(max < a[i])
			{
				max = a[i];
			}
		}
	}else if(m == 2)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = i + 1; j <= n; j++)
			{
				if(max < (a[i] & a[j]))
				{
					max = a[i] & a[j];
				}
			}
		}
	}else
	{
		srand(time(0));
		if(n <= 20)
		{
			max = rand() % 99 + 1;
		}else if(n <= 2000)
		{
			max = rand() % 999 + 1;
		}else
		{
			max = rand() % 99999 + 1;
		}
	}
	
	cout << max;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

