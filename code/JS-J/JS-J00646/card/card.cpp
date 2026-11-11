#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[500005], ans[500005];
map<int, int> ma;
stack<int> s;
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
		cin >> a[i];
		if(ma[a[i]] != 0) ma[a[i]] = 1, s.push(a[i]);
		else 
		{
			while(!s.empty())
			{
				int now = s.top();
				if(now == a[i])
				{
					s.pop();
                    break;
				}
				ma[now] = 0;
				s.pop();
            }
            ma[a[i]] = 1;
            s.push(a[i]);
		}
	}
	for(int i = 1; i <= m; i++)
	{
		if(ma[i] != 0)
		{
			ans[i]++;
		}
	}
	for(int i = 2; i <= n; i++)
	{
		
		for(int p = 1; p <= m; p++)
		{
			ma[p] = 0;
		}
		for(int j = i; j <= n; j++)
		{
		    ma[a[j]] = 1;
		}
		for(int k = 1; k <= m; k++)
		{
			if(ma[k] != 0) ans[k]++;
		}
	}
	for(int i = 1; i <= m; i++)
	{
		cout << ans[i] << " ";
	}
    return 0;
}
