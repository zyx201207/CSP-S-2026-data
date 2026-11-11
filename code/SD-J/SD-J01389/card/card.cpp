#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],times[300005];
bool vis[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		memset(vis,0,sizeof(vis));
		stack<int> st;
		for (int j = i; j <= n; j++)
		{
			if (!vis[a[j]])
			{
				st.push(a[j]);
				vis[a[j]] = 1;
			}
			else
			{
				while(st.top() != a[j] && st.size())
				{
					st.pop();
				}
			}
		}
		while(st.size())
		{
			int u = st.top();
			st.pop();
			times[u]++;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		cout << times[i] << ' ';
	}
	return 0;
}
