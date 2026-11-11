#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;

struct Node
{
	int a;
	char c;
};

vector<Node> s;

/*
 * aaavereefegf
 * 3 a
 * 1 v
 * 1 e
 * 1 r
 * 2 e
 * 1 f
 * 1 e
 * 1 g
 * 1 f
 * 12
*/

signed main()
{
#ifndef DEBUG
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
#endif

	cin.tie(0)->sync_with_stdio(0);

	int n, a;
	char c;

	cin >> n;
	cin >> a >> c;
	s.push_back({a, c});
	for (int i = 1; i < n; i++)
	{
		cin >> a >> c;
		if (s.back().c == c)
			s.back().a += a;
		else
			s.push_back({a, c});
	}

	int f = 0, e = s.size() - 1, ans = 0;
	// clog << f << e;
	while (f < e)
	{
		if (s[f].a > s[e].a)
		{
			// clog << "1a";
			s[f].a -= s[e].a;
			if (s[f].c != s[e].c)
			{
				ans += s[e].a;
			}
			e--;
		}
		else if (s[f].a < s[e].a)
		{
			// clog << "2b";
			s[e].a -= s[f].a;
			if (s[f].c != s[e].c)
			{
				ans += s[f].a;
			}
			f++;
		}
		else
		{
			// clog << "0c";
			if (s[f].c != s[e].c)
			{
				ans += s[f].a;
			}
			f++;
			e--;
		}
	}

	cout << ans << endl;
	// clog << static_cast<int>(1e9);
	return 0;
}