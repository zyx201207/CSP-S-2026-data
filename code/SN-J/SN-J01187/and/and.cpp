#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("add.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[n + 1];
	for (int i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	int sum = a[n];
	for (int i = n - 1 ; i > n - m ; i--)
	{
		sum = sum & a[i];
	}
	cout << sum;
	return 0;
}
