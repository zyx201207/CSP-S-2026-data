#include <bits/stdc++.h> 
using namespace std;
int n, m, a[200005], x = 0;
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		x = max(a[i], x);
	}
	cout << x;
	return 0;
} 
