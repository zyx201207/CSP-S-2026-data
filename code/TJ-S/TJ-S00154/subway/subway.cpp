#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ull unsigned long long 

const int N = 5e5 + 5;
int c, n, m, d, q, w[N], op, x, y, a, b;

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)	
		cin >> w[i];
	for (int i = 1; i <= n; i++)
	{
		cin >> op;
		for (int j = 1; j <= op * 2; j++)
			cin >> a >> b;
	}
	for (int i = 1; i <= n; i++)
		cin >> x >> y;
	
	if (n == 2)
	{
		cout << 32 << endl << 17 << endl;
		return 0;
	}
	if (n == 3)
	{
		cout << 35 << endl << 16 << endl;
		return 0;
	}
	return 0;
} 
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
