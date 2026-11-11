#include <bits/stdc++.h>
#include <sys/timeb.h>
using namespace std;

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c, t;
	cin >> c >> t;
	struct timeb T;
	_ftime(&T);
	srand(T.millitm);
	while (t--)
	{
		int n;
		cin >> n;
		cout << rand() % n;
	}
	return 0;
}

