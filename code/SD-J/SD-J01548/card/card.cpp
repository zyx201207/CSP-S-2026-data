#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e6 + 10;

int n, m;
int a[N];
int cnt[N];

signed main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i=1; i<=n; i++)
	{
		cin >> a[i];
	}
	for(int i=1; i<=n; i++)
	{
		deque<int> dq;
		bool vis[N] = {false};
		for(int j=i; j<=n; j++)
		{
			if(vis[a[j]] == false)
			{
				dq.push_back(a[j]);
			}
			else
			{
				for(int k=1; k<j; k++)
				{
					dq.pop_front(); 
				}
				dq.push_back(a[j]);
			}
			vis[a[j]] = true;
		}
		while(!dq.empty())
		{
			cnt[dq.front()]++;
			dq.pop_front();
		}
	}
	sort(a+1, a+n+1);
	for(int i=1; i<=m; i++)
	{
		cout << cnt[i] << " ";
	}
	return 0;
}
