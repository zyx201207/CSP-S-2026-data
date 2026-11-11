#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		
		cout << rand() % n + 1 << "\n";
	}
	return 0;
}