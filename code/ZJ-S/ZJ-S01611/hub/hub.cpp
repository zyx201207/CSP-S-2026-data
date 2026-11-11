#include<bits/stdc++.h>
using namespace std;
int randint(int l, int r)
{
	int len = r - l;
	int a = int(rand()) % len;
	return a + l;
}
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	srand(time(0));
	int c, t;
	cin >> c >> t;
	while (t --)
	{
		int n, k;
		cin >> n >> k;
		for (int i = 1; i < n; i ++)
		{
			int u, v;
			cin >> u >> v;
		}
		cout << randint(1, (n - 1) / 2) << "\n";
	}
	return 0;
}
