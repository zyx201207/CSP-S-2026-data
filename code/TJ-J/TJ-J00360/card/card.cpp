#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, M = 3e5 + 5;
int n, m, a[N], t[M];
stack<int> st;
bool find(int x, stack<int> &sta)
{
	while(!sta.empty())
	{
		int i = sta.top();
		sta.pop();
		if(i == x) return true;
	}
	return false;
}
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++)
	{
		while(!st.empty()) st.pop();
		for(int j = i; j <= n; j++)
		{
			if(!find(a[j], st)) st.push(a[j]);
			else
			{
				while(!st.empty()) if(find(a[j], st)) st.pop();
				st.push(a[j]);
			}
		}
		while(!st.empty())
		{
			t[st.top()]++;
			st.pop();
		}
	}
	for(int i = 1; i <= m; i++) cout << t[i] << ' ';
	return 0;
}
