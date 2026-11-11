#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	int n, m;
	cin >> n >> m;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int maxn = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > maxn) maxn = a[i];
	}
	cout << maxn;
	return 0;
}
