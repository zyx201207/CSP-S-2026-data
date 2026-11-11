#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 10;
int n, m;
int a[N], b[N], c[N];
signed main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	for(int i = 1; i <= n; i ++)
	{
		stack<int> stk;
		for(int j = i; j <= n; j ++)
		{
			if(b[a[j]]) 
			{
				while(stk.top() != a[j]) 
				{
					b[stk.top()] = 0;
					stk.pop();
				}
			}
			else 
			{
				stk.push(a[j]);
				b[a[j]] = 1;
			}
		}
		while(!stk.empty())
		{
			c[stk.top()] ++;
			stk.pop();
		}
	}	
	for(int i = 1; i <= m; i ++) cout << c[i] << " ";
	puts("");
	return 0;
}
//1000000000
