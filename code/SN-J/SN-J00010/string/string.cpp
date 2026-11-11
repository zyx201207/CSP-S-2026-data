#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen ("string.in","r",stdin);
	freopen ("string.out","w",stdout);
	int n,num,sum = 0,ans = 0;string let;
	string s;
	cin >> n;
	for (int i = 1;i <= n;i ++)
	{
		cin >> num >> let;
		sum += num;
		for (int j = 1;j <= num;j ++)s += let;
	}
	if (num % 2 == 0)
	{
		for (int i = 0;i <= (s.length() / 2 - 1);i ++)
		{
			if (s[s.length() - 1 - i] != s[i])
			{
				ans ++;
			}
		}
	}
	else
	{
		for (int i = 0;i <= (s.length() - 1) / 2 - 1;i ++)
		{
			if (s[s.length() - 1 - i] != s[i])
			{
				ans ++;
			}
		}
	}
	cout << ans;
	return 0;
	
	
}
