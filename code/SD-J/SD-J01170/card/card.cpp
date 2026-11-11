#include <bits/stdc++.h>
#define ll long long 
using namespace std;
ll n, m, a[500005], cnt[500005], vis[500005];
void subtask1()
{
	for (int i = 1; i <= n; i ++)
		cnt[a[i]] = i;
	//cout << cnt[3] << endl;
	for (int i = 1; i <= m; i ++)
		cout << cnt[i] << " ";
	return ;
}
void subtask2()
{
	stack <int> stk;
	for (int i = 1; i <= n; i ++)
	{
		for (int j = i; j <= n; j ++)
		{
			ll id, ok = 1, tot = 0;
			while (!stk.empty())
			{
				int y = stk.top();
				vis[++tot] = y;
				stk.pop();
				if (y == a[j])
				{
					id = y, ok = 0;
					break;
				}
			}
			//cout << id << endl;
			if (ok == 0) stk.push(a[j]);
			else
			{
				for (int i = tot; i >= 1; i --)
					stk.push(vis[i]);
				stk.push(a[j]);
			}
		}
		while (!stk.empty())
		{
			cnt[stk.top()] ++;
			stk.pop();
		}
	}
	for (int i = 1; i <= m; i ++)
		cout << cnt[i] << " ";
	return ;
}
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out","w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	bool ok = 1;
	for (int i = 1; i < n; i ++)
		if (a[i + 1] < a[i]) ok = 0;
	if (ok) subtask1();
	else subtask2();
	return 0;
} 
