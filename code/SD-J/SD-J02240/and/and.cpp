#include <bits/stdc++.h>
using namespace std;
#define maxn 200005
int n, m;
long long a[maxn];
bool vis[maxn];
void solve1()
{
	long long maxx = -1;
	for (int i = 1; i <= n; i++)
		maxx = max (maxx, a[i]);
	cout << maxx << endl;
}
void solve2()
{
	long long maxx = -1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i != j)
				maxx = max(maxx, a[i] & a[j]);
	cout << maxx << endl;
}
void solve3()
{
	long long maxx = a[2];
	for (int i = 3; i <= n; i++)
		maxx = maxx & a[i];
	for (int i = 2; i <= n; i++)
	{
		long long sum = a[1];
		for (int j = 2; j <= n; j++)
		{
			if (i != j) 
				sum = sum & a[j]; 
		}
		maxx = max(maxx, sum);
	}
	cout << maxx << endl;
}
void solve4()
{
	long long maxx = a[1];
	for (int i = 2; i <= n; i++)
		maxx = maxx & a[i];
	cout << maxx << endl; 
}
void solve()
{
	sort(a + 1, a + n + 1);
	long long maxx = a[n];
	for (int i = n - 1; i >= n - m + 1; i--)
		maxx = maxx & a[i];
	cout << maxx << endl;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r", stdin);
	freopen("and.out","w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (m == 1)
		solve1();
	else if (m == 2)
		solve2();
	else if (m == n - 1)
		solve3();
	else if (m == n)
		solve4();
	else solve();
	return 0;
}
