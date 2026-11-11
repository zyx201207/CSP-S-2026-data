#include<bits/stdc++.h>
using namespace std;
int a[int(2e5 + 5)] , cnt[int(2e5 + 5)];
bool used[int(2e5 + 5)];
int main()
{
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n , m;
	cin >> n >> m;
	for(int i = 1;i <= n;i = i + 1)
	{
		cin >> a[i];
	}
	stack<int> st;
	for(int i = 1;i <= n;i = i + 1)
	{
		for(int j = i;j <= n;j = j + 1)
		{
			if(used[a[j]] == 0)
			{
				used[a[j]] = 1;
				st.push(a[j]);
			}
			else
			{
				if(!st.empty() && st.top() != a[j])
				{
					while(!st.empty())
					{
						used[st.top()] = 0;
						st.pop();
						if(st.top() == a[j] && !st.empty())
						{
							used[a[j]] = 1;
							break;
						}
						if(st.empty())
						{
							used[a[j]] = 1;
							break;
						}
					}	
				}
				
			}
		}
		for(int i = 1;i <= m;i = i + 1)
		{
			cnt[i] = cnt[i] + used[i];
			used[i] = 0;
		}
	}
	for(int i = 1;i <= m;i = i + 1)
	{
		cout << cnt[i] << " ";
	}
	return 0;
}
