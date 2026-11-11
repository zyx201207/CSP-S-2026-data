#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.cpp","r",stdin);
	freopen("card.cpp","w",stdout);
	stack<int> s;
	int n, m, a[500005], sm[300005];
	cin >> n >> m;
	for(int i = 1;i <= n;i ++)
	{
		cin >> a[i];
	}
	for(int i = 1;i <= n;i ++)
	{
		int use[300005];
		for(int j = i; j <= n;j ++)
		{
			if(use[a[j]] == 0)
			{
				use[a[j]] = 1;
				s.push(a[j]);
			}
			else
			{
				while(s.top() != a[j])
				{
					use[s.top()] = 0;
					s.pop();
				}
			}
		}
		for(int j = i;j <=n;j ++)
		{
			if(use[a[j]] == 1)
			sm[a[j]] ++;
		}
	}
	for(int i = 1;i <= m;i ++)
	cout << sm[i] << " ";
	return 0;
}
