#include<bits/stdc++.h>

const int MAXN = 5e5 + 5, MAXM = 3e5 + 5;

int n, m, a[MAXN];

int stk[MAXN], top, ans[MAXM], vis[MAXM];

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
		
	for(int i = 1; i <= n; i++)
	{
		top = 0;
		for(int j = 1; j <= m; j++)
			vis[j] = 0;
		for(int j = i; j <= n; j++)
		{
			while(vis[a[j]])
				vis[stk[top--]]--;
			stk[++top] = a[j], vis[a[j]]++;
		}
		for(int j = 1; j <= top; j++)
			ans[stk[j]]++;
	}
	
	for(int i = 1; i <= m; i++)
		printf("%d%c", ans[i], (i == m ? '\n' : ' '));
		
	return 0; 
}
