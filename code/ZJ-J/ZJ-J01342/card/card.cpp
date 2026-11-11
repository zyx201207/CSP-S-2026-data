#include<bits/stdc++.h>
using namespace std;
const int N = 500005;
const int M = 300005;
int n, m;
int a[N];
int f[M];
int ans[M];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i ++)
	{
		stack<int> st;
		memset(f, 0, sizeof(f));
		for (int j = i; j <= n; j ++)
		{
			if (f[a[j]] == 1)
			{
//				cout << "1";
				while (st.top() != a[j])
				{
					f[st.top()] = 0;
					st.pop();
				}
//				st.pop();
//				st.push(a[j]);
			}
			else
			{
//				cout << "2";
				st.push(a[j]);
				f[a[j]] = 1;
			}
		}
		for (int i = 1; i <= m; i ++)
		{
			if (f[i])
			{
				ans[i] ++;
			}
		}
	}
	for (int i = 1; i <= m; i ++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/