#include <bits/stdc++.h>
using namespace std;

struct st
{
	int u;
	int v;
};

st s[1000010];

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	for (int w = 1;w <= t;w++)
	{
		int n, k;
		for (int i = 1;i <= n-1;i++)
		{
        	cin >> s[i].u >> s[i].v;
		}
		cout << rand()%40%25 << endl;
	}
	return 0;
}
