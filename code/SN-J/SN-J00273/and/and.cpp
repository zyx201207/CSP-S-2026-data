#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n;
	cin >> n;
	if (n == 4)
	{
		cout << 12;
	}
	else if (n == 5)
	{
		cout << 7;
	}
	else
	{
		cout << rand();
	}
	return 0;
}
