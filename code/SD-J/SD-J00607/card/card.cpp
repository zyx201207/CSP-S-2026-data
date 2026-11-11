#include <bits/stdc++.h>
using namespace std;

const int N = 500005, M = 300005;
int n, m;
int a[N];
int p[M];
int st[N], top = 0;
int ans[M];
bool flag = 0;;
int b[M];

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	a[0] = -1;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		b[a[i]]++;
		if (a[i] < a[i-1])
		{
			flag = 1;
		}
	}
	
	if (!flag)
	{
		for (int i = 1; i <= m; i++)
		{
			b[i] = b[i-1] + b[i];
			cout << b[i];
			if (i < m) cout << ' ';
		}
		return 0;
	}
	
	for (int i = 1; i <= n; i++)
	{
		memset(p, 0, sizeof(p));
		top = 0;
		for (int j = i; j <= n; j++)
		{
			if (p[a[j]] != 0 && p[a[j]] <= top && st[p[a[j]]] == a[j] ) 
			{
				top = p[a[j]];
			}
			else 
			{
				st[++top] = a[j];
				p[a[j]] = top;
			}
			
		}
		
		for (int i = 1; i <= top; i++)
		{
			ans[st[i]]++;
		}
		
	}
	
	for(int i = 1; i <= m; i++)
	{
		cout << ans[i];
		if (i < m) cout << ' ';
	}
	return 0;
}
