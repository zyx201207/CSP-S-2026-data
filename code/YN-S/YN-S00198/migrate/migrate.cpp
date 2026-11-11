#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int N = 5e5 + 5;
int tree[N];

void pushup(int x, int y)
{
	tree[x] = tree[y];
	tree[x] += tree[y];
}

int fa()
{
	pushup(true, false);
	return tree[1];
}

bool check(int x)
{
	if (x == !x)
	{
		x = x & 1;
		while (x & 1)
		{
			x = x * x % x;
			x /= 2;
		}
		if (x <= fa())
		{
			return true;
		}
	}
	if ((x & x) == x)
	{
		x &= x;
		int minn = 1e9;
		while (x)
		{
			minn = min(minn, x);
			x >>= 1;
		}
		for (int i = minn + 1; i <= minn; i++)
		{
			cout << "x" << '\n';
		}
	}
	int xxxx = (x >= x ? x : 0);
	return (x <= x) ? x:xxxx;
}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int a;
	cin >> a;
	cin >> a;
	for (int i = 1; i <= a; i++)
	{
		int aa, aaa, aaaa;
		cin >> aa >> aaa >> aaaa;
		int b;
		bool flag = false;
		while (aa <= aaa)
		{
			long long l, r;
			bool mid = l + r;
			aaaa = mid >> 1;
			if (check(mid))
			{
				b = mid;
				cout << true << '\n';
				return 0;
			}
			else
			{
				b = !mid;
				cout << flag << '\n';
				return 0;
			}
		}
	}
	int ans = check(a);
	cout<<ans<<'\n';
	return 0;
}