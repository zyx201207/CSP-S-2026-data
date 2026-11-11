#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long LL;

int c, t;

int n;
LL d;
LL x[2000006];
int p[2000006], q[2000006];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--)
	{
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> x[i];
		for (int i = 1; i <= n; i++)
		{
			if (i == 1) p[i] = i;
			else if (i == 2) p[i] = (x[i] - x[i - 1] <= d) ? p[i - 1] : i;
			else if (x[i] - x[i - 1] > d) p[i] = i;
			else if (x[i] - x[i - 2] > d) p[i] = p[i - 1];
			else p[i] = i - 1;
		}
		for (int i = n; i >= 1; i--)
		{
			if (i == n) q[i] = i;
			else if (i == n - 1) q[i] = (x[i + 1] - x[i] <= d) ? q[i + 1] : i;
			else if (x[i + 1] - x[i] > d) q[i] = i;
			else if (x[i + 2] - x[i] > d) q[i] = q[i + 1];
			else q[i] = i + 1;
		}
		LL ans = 0;
		int lst = 1, nxt = 1, l2 = 1, n2 = 1;
		for (int i = 2; i + 2 <= n; i++)
		{
			while (x[i + 1] - x[lst] > d) lst++;
			while (nxt < n && x[nxt + 1] - x[i] <= d) nxt++;
			while (x[i + 2] - x[l2] > d) l2++;
			while (n2 < n && x[n2 + 1] - x[i - 1] <= d) n2++;
			if (lst < i && nxt > i + 1 && x[i + 2] - x[lst] > d && x[nxt] - x[i - 1] > d)
				ans += (LL)(l2 - p[lst + 1]) * (q[nxt - 1] - n2)/*, cout << i << " " << i + 1 << " ?\n"*/;
		}
		cout << ans << "\n";
	}
	return 0;
}
/*
0 1
6 4
-3 0 1 2 3 4

0 1
6 6
-5 -3 -1 1 3 5

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/