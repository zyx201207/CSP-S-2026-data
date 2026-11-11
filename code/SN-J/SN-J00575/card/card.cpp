#include <bits/stdc++.h>
using namespace std;
string s;
long long n, m, a[50005], fd[30005], sum[30005];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++)
	{
		fd[i] = i;
		for(int j = 0; j < s.size(); j++)
		{
			if(s[j] != a[i])
			{
				s += a[i];
			}
			else
			{
				for(int k = 1; k <= j; k++)
				{
					s = " ";
					s += a[k];
				}
			}
		}
		for(int i = 0; i < s.size(); i++)
		{
			if(s[i] == fd[i])
			{
				sum[fd[i]]++;
			}
		}
	}
	for(int i = 1; i <= m; i++)
	{
		cout << sum[i] << " ";
	}
	return 0;
}
