#include <bits/stdc++.h>
using namespace std;
int a[500005], ans[300005];
bool vis[300005], chk[300005];
stack < int > st;
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
	{
		memset(vis, 0, sizeof vis);
		while (!st.empty()) st.pop();
		for (int j = i; j <= n; j++)
		{
			int k = a[j];
			if (vis[k])
			{
				while (!st.empty() && st.top() != k)
				{
					vis[st.top()] = 0;
					st.pop();
				}
				st.pop();
			}
			vis[k] = 1;
			st.push(k);
		}
		while (!st.empty())
		{
			ans[st.top()]++;
			st.pop();
		}
	}
	for (int i = 1; i <= m; i++)
		printf("%d ", ans[i]);
	return 0;
}
//X X XXX
//101011110010100011000
