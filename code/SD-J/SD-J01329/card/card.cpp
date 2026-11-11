#include<bits/stdc++.h>
using namespace std;
int n, m, a[500005]; 
int hav[300005];
bool vis[300005];
stack<int> stk;
void solve(int now)
{
	for(int i = now; i <= n; i ++)
	{
		if(vis[a[i]])
		{
			while(stk.top() != a[i])
			{
				vis[stk.top()] = 0;stk.pop();
			}
			vis[stk.top()] = 0;stk.pop();
		}
		vis[a[i]] = 1;
		stk.push(a[i]);
	}
} 
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	for(int i = 1; i <= n; i ++)
	{
		memset(vis, 0, sizeof(vis));
		while(stk.size()) stk.pop();
		solve(i);
		while(stk.size()) {
			hav[stk.top()] ++;
			stk.pop();
		}
	}
	for(int i = 1; i <= m; i ++)
		cout << hav[i] << ' ';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
