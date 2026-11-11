#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;

int N, M;
int a[500010];
stack<int>stk;
int ans[300010];
bool vis[300010];

void solve()
{
	cin >> N >> M;
	for(int i = 1; i <= N; i++) cin >> a[i];
	for(int i = 1; i <= N; i++)  // O(N(N + M))
	{
		while(!stk.empty()) stk.pop();
		memset(vis, 0, sizeof(vis));
		for(int j = i; j <= N; j++)
		{
			int num; num = a[j];
			if(!vis[num]) vis[num] = 1;
			else if(vis[num])
			{
				while(!stk.empty())
				{
					int x = stk.top();
					vis[x] = 0;
					stk.pop();
					if(x == num) break;
				}
				vis[num] = 1;
			}
			stk.push(num);
		}
		for(int j = 1; j <= M; j++)
			if(vis[j]) ans[j]++;
	}
	for(int i = 1; i <= M; i++) 
		cout << ans[i] << " ";
}

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	solve();
	return 0;
}

