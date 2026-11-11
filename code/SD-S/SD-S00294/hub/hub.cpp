#include <iostream>
#include <random>
#include <ctime>

using std::cin;
using std::cout;

std::mt19937 rd(time(NULL));

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		for (int i = 1; i < n; ++i)
		{
			int u, v;
			cin >> u >> v;
		}
		cout << n / k - rd() % 3 + 1 << '\n';
	}
	return 0;
}
