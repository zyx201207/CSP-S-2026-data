#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum[500005],t[500005],p[500005];
stack <int> s,sf;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	if(n <= 5000)
	{
		for(int i = 1;i <= n;i++)
		{
			cin >> a[i];
		}
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= n;j++)
			{
				t[a[j]] = 0;
			}
			for(int j = i;j <= n;j++)
			{
				if(t[a[j]] == 0)
				{
					s.push(a[j]);
					t[a[j]] = 1;
				}
				else if(t[a[j]] == 1)
				{
					while(s.top() != a[j])
					{
						t[s.top()] = 0;
						s.pop();
					}
				}
				
			}
			while(!s.empty())
			{
				sum[s.top()]++;
				s.pop();
			}
		}
		for(int i = 1;i <= m;i++)
		{
			cout << sum[i] << " ";
		}
	}
	else
	{
		for(int i = 1;i <= n;i++)
		{
			cin >> a[i];
		}
		for(int i = n;i >= 1;i--)
		{
			if(t[a[i]] == 0)
			{
				s.push(a[i]);
				t[a[i]] = 1;
				p[a[i]] = i;
			}
			if(t[a[i]] == 1)
			{
				while(s.top() != a[i])
				{
					t[s.top()] = 0;
					sum[s.top()] += p[s.top()] - i;
					p[s.top()] = n;
					s.pop();
				}
			}
		}
		while(!s.empty())
		{
			sum[s.top()] += p[s.top()];
			s.pop();
		}
		for(int i = 1;i <= m;i++)
		{
			cout << sum[i] << " ";
		}
	}
	return 0;
}
