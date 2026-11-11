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
#include <stack>
using namespace std;

typedef long long ll;

const int N = 5e5 + 10;
int n, m, a[N], st[N], len, to[N];

signed main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++)
	{
		memset(st, 0, sizeof(st));
		len = 0;
		for(int j = i; j <= n; j++)
		{
			for(int k = 1; k <= len; k++)
			{
				if(st[k] == a[j]) 
				{
					len = k - 1;
					break;
				}
			} 
			st[++len] = a[j];
//			for(int k = 1; k <= len; k++) cout << st[k] << ' ';
//			cout << endl;
		}
		for(int j = 1; j <= len; j++)
		{
			to[st[j]]++;
		}
	}
	for(int i = 1; i <= m; i++) cout << to[i] << ' ';
	return 0;
}
