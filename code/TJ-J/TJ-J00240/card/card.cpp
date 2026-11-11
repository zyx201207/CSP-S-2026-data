#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 10;
queue<int> q;
int cnt[N];
int fin[N];
int n, m;
int game = 1;
int now = 1;
int pos;
int ans[N];
signed main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		q.push(x);
	}
	while(game < n)
	{
		while(!q.empty())
		{
			int u = q.front();
			q.pop();
			if(cnt[u] == 1)
			{
				for(int i = 1; i <= n; i++)
				{
					if(fin[i] == u)
					{
						pos = i;
						break;
					}
				}
				cout << u << " " << pos << endl;
				for(int i = pos; i <= n; i++)
				{
					fin[pos] = 0;
				}
				fin[pos] = u;
				cnt[u]++;
				now = pos;
			}
			else
			{
				fin[now] = u;
				cnt[u]++;
			}
		}
		for(int i = 1; i <= n; i++)
		{
			ans[fin[i]]++;
			q.push(fin[i]);
			fin[i] = 0;
		}
		game++;
	}
	for(int i = 1; i <= m; i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}
