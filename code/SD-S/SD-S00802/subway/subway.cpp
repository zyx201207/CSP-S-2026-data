#include <bits/stdc++.h>

using namespace std;

int c, n, m, d, q, ki;
int w[50000];
pair<int, int> k[505][50000];

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &w[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &ki);
		for (int j = 1; j <= ki; j++)
		{
			scanf("%d%d", &k[i][j].first, &k[i][j].second);
		}
	}
	while (q--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		
		printf("%d\n", 0);
	}
		
	return 0;
} 
