#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10, M = 3e5 + 10;
int n, m;
int a[N], res[M];
int st[M], tmp[N];
stack<int> s;

bool check()
{
	for(int i = 1; i <= n; i ++)
		if(a[i] > a[i + 1])
			return false;
	return true;
}
void add(int x)
{
	for(int i = x; i <= n; i ++)
		if(tmp[i] != 2) res[a[i]] ++; 
}
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	if(check())
	{
		int ans = n + 1;
		for(int i = 1; i <= n; i ++)
			res[a[i]] = ans - i;
		for(int i = 1; i <= m; i ++)
		cout << res[i] << " ";
		return 0;
	}
	
	for(int i = 1; i <= n; i ++)
	{
		memset(st, 0, sizeof st);
		memset(tmp, 0, sizeof tmp);
		for(int j = i; j <= n; j ++)
		{
			if(st[a[j]] == 0)
			{
				s.push(j);
				st[a[j]] = 1, tmp[j] = 1;
			}
			else
			{
				while(a[s.top()] != a[j])
				{
					int u = s.top(); s.pop();
					st[a[u]] = 0, tmp[u] = 2;
				}
				tmp[s.top()] = 2;s.pop();
				s.push(j), tmp[j] = 1;
			}
		}
		add(i);
	}
	for(int i = 1; i <= m; i ++)
		cout << res[i] << " ";
	puts("");
	return 0;
}
