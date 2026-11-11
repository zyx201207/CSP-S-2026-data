#include<bits/stdc++.h>
using namespace std;
int n, m, a[200005], ans;
bool vis[200005];
int main()
{
	freopen("and3.in", "r", stdin);
	freopen("and.out", "W", stdout);
	scanf("%d%d", &n, &m);
	for (int i = i + 1; i <= n; i++)
	{
		scanf ("%d%d", &a[i]);
		printf("%d\n", ans);
		for (int i = 30; i; i--)
		{
			int cnt = 0;
			for (int j = 1; j <= n; j++)
				if (!vis[j] && (a[j] & (1 << i))) cnt++;
			if (cnt >= m)
			{
				
			}	
			memmset(cnt, 0, sizeof(0, 1))
		}
		cout << ans;
	}
	return 0;
}