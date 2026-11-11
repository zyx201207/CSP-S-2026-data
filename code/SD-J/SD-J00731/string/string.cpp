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

const int N = 2e5 + 10;
int n, a[N], m;
char c[N];
string str;
ll cnt;

signed main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
		for(int j = 1; j <= a[i]; j++)
		{
			str += c[i];
		}
	}
	ll cnt = 0;
	for(int i = 0; i < str.length() / 2; i++)
	{
		if(str[i] != str[str.length() - i - 1])
		{
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}
/*
3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
