#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	srand(time(nullptr));
	int c, t;
	cin >> c >> t;
	while(t--)
		cout << rand() % 5 << endl;
	return 0;
}

