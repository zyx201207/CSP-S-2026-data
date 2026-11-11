#include <bits/stdc++.h>
using namespace std;
int t;
int n, d;
int a[1145141];
int ppw;
vector<int> b[114];
int ans;

void dfs(int x, int s)
{
	for (int i = x + 1; i <= n; ++i)
	{
		if (a[i] - a[x] <= d)
		{
			b[i].push_back(s + 1);
			dfs(x, s + 1);
		}
	}
}

int cmp(int a, int b)
{
	return a > b;
}

int main()
{
	int c;
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--)
	{
		int ans = 0;
//		cin >> n >> d;
//		for (int i = 1; i <= n; ++i)
//		{
//			cin >> a[i];
//		}
//		for (ppw = 1; ppw <= n; ++ppw)
//		{
//			memset(b, 0, sizeof(b));
//			dfs(ppw, 0);
//			for (int i = 1; i <= n; ++i)
//			{
//				sort(b[i].begin(), b[i].end(), cmp);
//				if (b[i][0] == b[i][1] && b[i][1] != b[i][2] && b[i][0] != 0)
//				{
//					++ans;
//				}
//			}
//		}
		cout << ans << endl;
	}
}
// fuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuck
