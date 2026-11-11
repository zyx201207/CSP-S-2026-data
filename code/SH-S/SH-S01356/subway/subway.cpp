#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct st
{
	ll a, t;
};
int c, n, m, d, q;
ll w[500009];
st la[500009], lb[500009], lc[500009];
ll ka, kb, kc;
int main()
{
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
	{
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> ka;
		for (int i = 1; i <= ka; i++)
		{
			cin >> la[i].a >> la[i].t;
		}
	}
	while (q--)
	{
		int x, y;
		cin >> x >> y;
		cout << w[x] + w[y] << endl;
	}
	return 0;
}
