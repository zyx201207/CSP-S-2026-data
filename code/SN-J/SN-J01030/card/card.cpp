#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, m;
	
	cin >> n >> m;
	
	vector<int> a(n);
	vector<int> ans(m + 1, 0);
	
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	
	for(int j = 0; j < n; j++)
	{
		stack<int> idx[n];
		stack<int> st;
		
		for(int i = j; i < n; i++)
		{
			if(idx[a[i]].size() == 0)
			{
				st.push(a[i]);
				idx[a[i]].push(a[i]);
			}
			else
			{
				while(st.size() != 0 and st.top() != idx[a[i]].top())
				{
					if(idx[st.top()].size() != 0)
					{
						idx[st.top()].pop();
					}
					
					st.pop();
				}
			}
		}
		
		while(st.size() != 0)
		{
			ans[st.top()]++;
			
			st.pop();
		}
	}
	
	for(int i = 1; i <= m; i++)
	{
		cout << ans[i] << " ";
	}
	
	return 0;
}
