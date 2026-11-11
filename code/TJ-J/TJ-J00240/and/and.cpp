#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int ans;
int n, m;
int a[N];
int er[N];
bool cmp(int x, int y)
{
	if(x > y)
	{
		return true;
	}
	return false;
}
int time(int x, int y)
{
	if(x == 0)
	{
		return 1;
	}
	if(y == 0)
	{
		return 0;
	}
	for(int i = 1; i <= x; i++)
	{
		y *= 2;
	}
	return y;
}
void an(int x, int y)
{
	int pos = 0;
	int xx = 0;
	while(x != 0 && y != 0)
	{
		er[pos] = x & y;
		pos++;
		x >>= 1;
		y >>= 1;
		int z = time(pos, er[pos]);
		xx += z;
	}
	ans = max(ans, xx);
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	int z = 1;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(a[i] = z)
		{
			ans = max(ans, z);
		}
		else
		{
			z = a[i];
		}
	}
	sort(a + 1, a + 1 + n, cmp);
	for(int i = 2; i <= 20; i++)
	{
		an(a[1], a[i]);
	}
	cout << ans;
	return 0;
}
