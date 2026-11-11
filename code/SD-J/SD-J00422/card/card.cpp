#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	int a[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	stack<int> pd;
	int b[n] = {0};
	int sum[m];
	for (int i = 0; i < m; i++)
	{
		sum[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			int y = a[j];
			if (b[y] == 0)
			{
				pd.push(y);
				b[y]++;
			} else {
				while (pd.top() != y)
				{
					int x = pd.top();
					b[x]--;
					pd.pop();
				}
			}
		}
		for (int p = 0; p < pd.size(); p++)
		{
			int q = pd.top();
			sum[q]++;
			pd.pop();
		}
	} 
	for (int i = 1; i <= m; i++)
	{
		int s = sum[i];
		printf("%d", s);
	}
	return 0;
}
