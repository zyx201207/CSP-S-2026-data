#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1010101], b[1010101];
int ans[1010101];
stack <int> s, s1;
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		memset(b, 0, sizeof(b));
		for (int j = i; j <= n; j++)
		{
			s.push(a[j]);
			b[a[j]]++;
			if (b[a[j]] == 2) 
			{
				s.pop();
				while (s.top() != a[j] && !s.empty()) 
				{
					//cout << s.top() << " ";
					s.pop();
				}
				b[a[j]]--;
			}	
		}
		while (!s.empty()) 
		{
			ans[s.top()]++;
			s.pop();
		}
	}
	for (int i = 1; i <= m; i++) cout << ans[i] << " ";
	return 0;
}