#include <bits/stdc++.h>
using namespace std;
int n, a[500005], m, book1[300005], book2[300005], ans[300005];
stack<int> s, empty_s;
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int j = 1; j <= n; j++)
	{
		s = empty_s;
		memset(book1, 0, sizeof(book1));
		memset(book2, 0, sizeof(book2));
		for (int i = j; i <= n; i++)
		{
			if (book1[a[i]] == 0) book1[a[i]]++;
			else
			{
				while (s.top() != a[i])
				{
					book1[s.top()]--;
					s.pop();
				}
				s.pop();
			}
			s.push(a[i]);
		}
		while (!s.empty())
		{
			int temp = s.top();
			s.pop();
			if (book2[temp] == 0)
			{
				book2[temp] = 1;
				ans[temp]++;
			}
		}
	}
	for (int i = 1; i <= m; i++) cout << ans[i] << ' ';
	return 0;
}
