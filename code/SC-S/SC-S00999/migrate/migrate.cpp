#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;
int a [N];

int main ()
{
	freopen ("migrate.in" , "r" , stdin);
	freopen ("migrate.out" , "w" , stdout);
	int c , T;
	cin >> c >> T;
	while (T --)
	{
		memset (a , 0 , sizeof (a));
		int n;
		cin >> n;
		for (int i = 1;i <= n;i++)
		{
			cin >> a [i];
		}
		cout << n - 2 << "\n";
	}
	return 0;
}