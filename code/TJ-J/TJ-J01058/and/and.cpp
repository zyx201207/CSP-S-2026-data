#include <iostream>
#include <algorithm>
using namespace std;

int maxn = 0;
int n, m;
int a[200020];

void dfs(int step, int ans, int stop)
{
	if(step == m)
	{
		maxn = max(maxn, ans);
		return;
	}
	for (int i = stop + 1; i <= n; i++)
	{
		if(step == 0) dfs(step + 1, a[i], i);
		dfs(step + 1, ans & a[i], i);
	}
	return;
}

int main()
{
	freopen("and3.in", "r", stdin);
	freopen("and3.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	if(m == 1)
	{
		cout << a[n];
		return 0;
	}
	if(n == m)
	{
		int sum = a[1];
		for (int i = 1; i <= n; i++)sum &= a[i];
		cout << sum;
		return 0;
	} 
	dfs(0, 0, 0);
	cout << maxn;
	return 0;
}
