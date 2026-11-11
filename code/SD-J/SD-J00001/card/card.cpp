#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	long long n, m;
	cin >> n >> m;
	long long a[500005];	// 5 * 10^5
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	
	long long tong[300005] = {0};	// 3 * 10^5
	long long stack[500005], tou = 0;	// 5 * 10^5
	for(int i = 1; i <= n; i++)
	{
		for(int j = i; j <= n; j++)
		{
			for(int k = tou; k >= 1; k--)
			{
				if(stack[k] == a[j])
				{
					tou = k - 1;
					continue;
				}
			}
			stack[++tou] = a[j];
		}
		
		for(int i = 1; i <= tou; i++)
		{
			tong[stack[i]]++;
		}
		
		tou = 0;
	}
	
	for(int i = 1; i <= m; i++)
	{
		cout << tong[i] << " ";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

