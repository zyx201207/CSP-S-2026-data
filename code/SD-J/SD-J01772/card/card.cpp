#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10, M = 3e5 + 10;
int a[N];
int bkt[N];
int ans[N];
inline int read()
{
	int x = 0, c = getchar(), k = 1;
	while (c != '-' && (c < '0' || c > '9')) c = getchar();
	if (c == '-') k = -1, c = getchar();
	do x = x * 10 + (c ^ 48), c = getchar();
	while ('0' <= c && c <= '9');
	return x * k; 
}
inline void write(int x)
{
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar(x % 10 ^ 48);
}
signed main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n = read(), m = read();
	for (int i = 1; i <= n; i ++)
		a[i] = read();
	for (int i = 1; i <= n; i ++)
	{
		memset(bkt, 0, sizeof bkt);
		stack<int> stk;
		for (int j = i; j <= n; j ++)
		{
			if (bkt[a[j]])
			{
				int t;
				do
				{
					t = stk.top();
					bkt[t] --;
					stk.pop();
				} while (t != a[j]);
			}
			stk.push({a[j]});
			bkt[a[j]] ++;
		}
		for (int j = 1; j <= m; j ++)
			if (bkt[j]) ans[j] ++;
	}
	for (int i = 1; i < m; i ++)
		write(ans[i]), putchar(' ');
	write(ans[m]);
	return 0;
}
