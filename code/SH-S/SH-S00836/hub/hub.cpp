#include <bits/stdc++.h>
using namespace std;
int a[1000001], b[1000001];
int main ()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		for (int i = 1; i < n; i++) cin >> a[i] >> b[i];
		cout << m - 1 << "\n";
	}
	return 0;
}
