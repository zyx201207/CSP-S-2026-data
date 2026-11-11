#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n, m; cin >> n >> m;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	vector<int> lev(m + 1, 0), exi(m + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		stack<int> st;
		exi.assign(m + 1, 0);
		for (int j = i; j <= n; j++)
		{
			if (exi[a[j]] == 0)
			{
				exi[a[j]] = 1;
				st.push(a[j]);
			}
			else
			{
				while (!st.empty())
				{
					if (st.top() == a[j]) break;
					exi[st.top()] = 0;
					st.pop();
				}
			}
		}
		while (!st.empty())
		{
			//cout << st.top() << " ";
			lev[st.top()]++;
			st.pop();
		}
	}
	
	for (int i = 1; i <= m; i++) cout << lev[i] << " ";
	return 0;
}
