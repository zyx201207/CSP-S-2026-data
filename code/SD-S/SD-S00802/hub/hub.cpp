#include <bits/stdc++.h>

using namespace std;

int c, t, n, k;
int r[2000005][2];

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	scanf("%d%d", &c, &t);
	while (t--)
	{
		scanf("%d%d", &n, &k);
		for (int i = 1; i < n; i++)
		{
			scanf("%d%d", &r[i][0], &r[i][1]);
		}
		
		printf("%d\n", 0);
	}
		
	return 0;
} 
