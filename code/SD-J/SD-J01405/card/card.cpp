#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 5;
const int M = 3e5 + 5;
int n,m;
int a[N];
bool live[N];
int t[N];

signed main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
//	cout << "sgfbsfg " << '\n';
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
	{
		cin >> a[i];
//		cout << "df lgkhbsdfl " << '\n';
	}
//	cout << "-----------" << '\n';
	
	for (int start = 1; start <= n; start ++)
	{
		stack<int> st;
		memset(live, 0, sizeof live);
		for (int i = start; i <= n; i ++)
		{
			if (live[a[i]])
			{
				while (!st.empty() and st.top() != a[i])
				{
					live[st.top()] = 0;
					st.pop();
				}
				if (!st.empty() && st.top() == a[i])
				{
					st.pop();
				}
				st.push(a[i]);
			}
			else
			{
				live[a[i]] = 1;
				st.push(a[i]);
			}
		}
		while (!st.empty())
		{
			t[st.top()] ++;
//			cout << st.top() << ' ';
			st.pop();
		}
//		cout << '\n';
	}
	
	for (int i = 1; i <= m; i ++)
	{
		cout << t[i] << ' ';
	}
	
	
	
	return 0;
}
/*

4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1

*/
 

