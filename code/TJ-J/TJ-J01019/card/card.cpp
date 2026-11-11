#include <cstdio>
#include <cstring>

const int N = 5e5+5, M = 3e5+5;
int n, m, a[N], top, st[N], ans[M];
bool v[M];

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; i++)
	{
		scanf("%d", &a[i]);
	}
	for(int i=1; i<=n; i++)
	{
		memset(st, 0, sizeof(st));
		memset(v, 0, sizeof(v));
		top = 0;
		for(int j=i; j<=n; j++)
		{
			if(v[a[j]])
			{
				while(top && a[st[top]] != a[j])
				{
					v[a[st[top]]] = false;
					top --;
				}
			}
			else
			{
				v[a[j]] = true;
				st[++top] = j;
			}
		}
		while(top)
		{
			
			ans[a[st[top]]] ++;
			top --;
		}
	}
	for(int i=1; i<=m; i++)
		printf("%d ", ans[i]);
	printf("\n");
	
	return 0;
}
