#include <bits/stdc++.h>
using namespace std;

int main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef DEBUG
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
#endif // DEBUG
#ifdef DEBUG
#endif // DEBUG
	int n, m;
	cin >> n >> m;
	static vector<int> a(n);
	for(int &x : a)
		cin >> x;
	static vector<int> na(n);
	for(int k = 30; k >= 0; k--)
	{
		int cnt = 0;
		for(int x : a)
			if(x & (1 << k))
				cnt++;
		if(cnt >= m)
		{
			for(int x : a)
				if(x & (1 << k))
					na.push_back(x);
			a = na;
		}
		na.clear();
	}
	int ans = 0x7fffffff;
	for(int x : a)
		ans &= x;
	cout << ans << '\n';

	return 0;
}

