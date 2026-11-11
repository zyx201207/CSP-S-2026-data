#include <cstdio>
#include <algorithm>

const int N = 2e5+5, M = 1e3+5;
int n, m, a[N];
long long ans;

void dfs(int pos, int id, long long num)
{
	if(pos > m)
	{
		ans = std::max(ans, num);
		return;
	}
	for(int i=id+1; i<=n; i++)
	{
		dfs(pos+1, i, num&a[i]);
	}
}

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; i++)
	{
		scanf("%lld", &a[i]);
	}
	if(n <= 2000)
	{
		for(int i=1; i<=n; i++)
		{
			dfs(2, i, a[i]);
		}
		printf("%lld\n", ans);
	}
	else
	{
		std::sort(a+1, a+n+1);
		printf("%lld\n", a[n-m+1]);
	}
	
	return 0;
}
