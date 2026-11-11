#include <bits/stdc++.h>
using namespace std;

vector<int> a;

int main()
{
#ifndef DEBUG
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
#endif
	cin.tie(0)->sync_with_stdio(0);

	int n, m;

	cin >> n >> m;
	a.resize(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	for (int i = 1; i <= m; i++)
	{
		cout << upper_bound(a.begin(), a.end(), i) - 1 - a.begin() << " ";
	}

	cout << endl;

	return 0;
}