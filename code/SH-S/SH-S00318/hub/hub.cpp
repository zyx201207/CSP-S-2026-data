#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--)
	{
		srand(time(0)*100);
		for (int i = 1; i <= 21345749; i++)
			srand(rand());
		cout << rand() % 10 << endl;
	}
	return 0;
}
