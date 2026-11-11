#include <iostream>
#include <algorithm>

int n, m;
int a[200001];
int ans = 0;

void dfs(int i, int c, int v)
{
	if(i > n + 1)
	{
		return;
	}
	if(c == m)
	{
		ans = std::max(ans, v);
		return;
	}
	if(c == 0)
	{
		dfs(i + 1, c + 1, a[i]);
	} else 
	{
		dfs(i + 1, c + 1, v & a[i]);
	}
	dfs(i + 1, c, v);
}

int main(int argc, char* argv[])
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	std::cin >> n >> m;
	for(int i = 1;i <= n;i ++)
	{
		std::cin >> a[i];
	}
	if(m == n)
	{
		int x = a[1];
		for(int i = 2;i <= n;i ++)
		{
			x &= a[i];
		}
		std::cout << x;
		return 0;
	}
	if(n > 2000)
	{
		std::sort(a + 1, a + n + 1, std::greater<int>());
		int x = a[1];
		for(int i = 2;i <= m;i ++)
		{
			x &= a[i];
		}
		std::cout << x;
		return 0;
	}
	dfs(0, 0, 0);
	std::cout << ans;
	return 0;
}
