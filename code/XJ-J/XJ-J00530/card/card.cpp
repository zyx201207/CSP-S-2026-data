#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","W",stdout);
	int n, a[105], b;
	cin >> n >> b;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << n << b << a[0];
	return 0;
}