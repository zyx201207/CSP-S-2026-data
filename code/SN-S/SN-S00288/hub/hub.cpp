// hub

#include <bits/stdc++.h>

using namespace std;

int c, T, n, k;

inline void solve()
{
	cin >> n >> k;
	int x, y;
	for (int i = 2; i <= n; i ++) cin >> x >> y;
	n = n / 2 - k;
	cout << ceil(1.0 * n / 4) + 1 << endl;
}

inline void clear()
{
	
}

int main()
{
	freopen("hub.in" , "r", stdin );
	freopen("hub.out", "w", stdout);
	
	cin >> c >> T;
	while (T --)
	{
		solve();
		clear();
	}
	
	
	return 0;
}
