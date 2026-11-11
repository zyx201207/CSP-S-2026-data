#include <bits/stdc++.h>
using namespace std;
int n, m, a[200005];
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	int mx = -1, andd = 1;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if(a[i] >= mx)
			mx = a[i];
		andd &= a[i];
	}
	if(m == 1)
	{
		cout << mx;
		return 0;
	}
	if(m == n)
	{
		cout << andd;
		return 0;
	}
	return 0;
}
// 
