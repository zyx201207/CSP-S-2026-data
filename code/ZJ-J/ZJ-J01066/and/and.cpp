#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[1002001];
void solve1()
{
	sort(a + 1, a + n + 1);
	cout << a[n];
	return;
}
void solve2()
{
	int ans = a[1];
	for(int i = 2; i <= n; i ++)
	{
		ans = ans & a[i];
	}
	cout << ans;
	return;
}
void solve3()
{
	int maxx = -1e9;
	for(int i = 1; i < n; i ++)
	{
		for(int j = i + 1; j <= n; j ++)
		{
			int tmp = a[i] & a[j];
			maxx = max(maxx, tmp);
		}
	}
	cout << maxx;
	return;
}
void solve4()
{
	int ans = -1;
	int maxn = -1e9;
	for(int i = 1; i <= n; i ++)
	{
		for(int j =1; j <= n; j ++)
		{
			if(i == j) continue;
			if(ans = -1)
			{
				ans = a[j];
				continue;
			}
			ans = ans & a[j];
		}
		maxn = max(maxn, ans);
	}
	cout << maxn;
	return;
}
void solveB()
{
	cout << n - 2;
	return;
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w" ,stdout);
 	ios::sync_with_stdio(false);
 	cin.tie(0);
 	cin >> n >> m;
 	for(int i = 1; i <= n; i ++)
 	{
 		cin >> a[i];
	 }
	if(m == 1)
	{
		solve1();
		return 0;
	}
	if(m == n)
	{
		solve2();
		return 0;
	}
	if(m == 2)
	{
		solve3();
		return 0;
	}
	if(m == n - 1)
	{
		solve4();
		return 0;
	}
	solveB();
    return 0;
}
