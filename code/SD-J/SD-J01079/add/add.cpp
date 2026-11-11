#include <iostream>
using namespace std;
int a[100000];
int n, m, maxx = 0, ii;
void dfs(int i, int x, int l)
{
	if(i == 0)
	{
		if(x > maxx)
		{
			maxx = x;
		}
		return;
	}
	if(l > ii)
	{
		return;
	}
	for(int w = 1; w <= 2; w++)
	{
		if(w == 1)
		{
			x = x&a[l];
			dfs(i--, x, l++);
		}else if(w == 2)
		{
			dfs(i, x, l++);
		}
	}	
}
int main()
{
	freopen("add.in", "r", stdin);
	freopen("add.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(i >= m)
		{
			dfs(i, 1, 1);
			ii = i;
		}
	}
	cout << maxx;
	return 0;
}
