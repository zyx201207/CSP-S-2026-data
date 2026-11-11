#include <iostream>
#include <string>

#define LL long long

const int N = 2e5 + 1;

int idx;
int n, m;
int a[N];
int res = 0;

void dfs(int idx, int d, int r)
{
	if(d == m)
	{
		res = std::max(r, res);
		return;	
	}
	for(int i = idx + 1; i < n; i++)
	{
		dfs(i, d + 1, r & a[i]);
	}
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	std::cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		std::cin >> a[i];
	}
	dfs(-1, 0, 2147483647);
	std::cout << res << '\n';
}


