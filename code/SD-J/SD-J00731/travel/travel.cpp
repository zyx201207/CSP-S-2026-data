#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#define endl '\n'
#define lc (x << 1)
#define rc (x << 1 | 1)
#define mid ((l + r) >> 1)

using namespace std;

typedef long long ll;
string x1, x2, y1, y2;

signed main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> x1 >> y1 >> x2 >> y2;
	bool f1 = 0, f2 = 0, f3 = 0;
	if(x1[0] == x2[0] && x1[1] == x2[1])
	{
		cout << 1;
		f1 = 1;
	}
	else cout << 0;
	if(y1[0] == y2[0] && y1[1] == y2[1] && f1)
	{
		cout << 1;
		f2 = 1;
	}
	else cout << 0;
	char R = y1[2], C = y2[2];
	if(((R == 'A' && (C == 'B' || C == 'C')) || (R == 'B' && (C == 'A' || C == 'C')) || (R == 'C' && (C == 'A' || C == 'B')) || (R == 'D' && C == 'F') || (R == 'F' && C == 'D')) && f2)
	{
		cout << 1;
		f3 = 1;
	}
	else cout << 0;
	if((R == 'A' && C == 'B') || (R == 'B' && f3) || (R == 'C' && C == 'B') || (R == 'D' && f3) || (R == 'F' && f3))
	{
		cout << 1;
	}
	else cout << 0;
	return 0;
}
