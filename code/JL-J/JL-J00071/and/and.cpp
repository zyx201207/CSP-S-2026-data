#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int m, n, sum = 0;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++)
	{
		if(sum < a[i])
			sum = a[i];
	}
	cout << sum;
	return 0;
}
