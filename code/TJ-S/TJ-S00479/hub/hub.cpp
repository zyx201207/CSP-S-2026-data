#include <algorithm>
#include <iostream>
#include <cstdio> 
#include <map>
#define ll long long
using namespace std;

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, T;
	cin >> c >> T;
	while (T--)
	{
		int n, k;
		cin >> n >> k;
		for (int i = 1; i < n; i++)
		{
			int u, v;
			cin >> u >> v;
		}
		cout << max(1, n / k - 1) << '\n';
	}
	return 0;
}
//-static-libgcc
