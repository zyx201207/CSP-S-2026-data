#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","W",stdout);
	int n, a[105], b;
	cin >> n >> b;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << a[n - 1];
	return 0;
}