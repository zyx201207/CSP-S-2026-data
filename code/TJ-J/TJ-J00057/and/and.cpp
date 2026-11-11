#include <iostream>
using namespace std;
int n, m, f, a[200005];
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		f = max(f, a[i]);
	}
	cout << (int)(rand() / f);
	return 0;
} 
