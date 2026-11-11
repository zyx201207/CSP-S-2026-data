#include <bits/stdc++.h>
using namespace std;
#define maxn 500005
int n, m;
int a[maxn], b[maxn];
int cnt;
int dis[maxn];
int vis[maxn];
deque<int> q;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r", stdin);
	freopen("card.out","w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int cas = 1; cas <= n; cas++)
	{
		cnt = -1;
		q.clear();
		for (int i = cas; i <= n; i++)
		{
			vis[i] = 0;
			dis[i] = 0;
		}
		for (int j = cas; j <= n; j++)
		{
			if(vis[a[j]] == 0)
			{
				q.push_back(a[j]);
				vis[a[j]] = 1;
				dis[a[j]] = ++cnt;
			}
			else
			{
				for (int k = dis[a[j]]; k <= cnt; k++)
					q.pop_back();
				cnt = q.size();
				q.push_back(a[j]);
				vis[a[j]] = 1;
				dis[a[j]] = ++cnt;
			}
		}
		while(q.size())
		{
			int x = q.front();
			q.pop_front();
			b[x] ++;
		}
	}
	for (int i = 1; i <= m; i++)
		cout << b[i] << " ";
	cout << endl; 
	return 0;
}
