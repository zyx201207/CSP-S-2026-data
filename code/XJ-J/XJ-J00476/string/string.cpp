#include <bits/stdc++.h>
using namespace std;
bool similar(string s)
{
	for (int i = 1; i < s.length() / 2; i++)
	{
		if (s[i] != s[i-1])
		{
			return false;
		}
	}
	for (int i = s.length() / 2; i < s.length() / 2; i++)
	{
		if (s[i] != s[i-1])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	long long a[n+1];
	char c[n+1];
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
	}
	string s = "";
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= a[i]; j++)
		{
			s += c[i];
		}
	}
	if (n == 1)
	{
		cout << "0";
		return 0;
	}
	bool flag1 = true;
	for (int i = 1; i < s.length(); i++)
	{
		if (s[i] != s[i-1])
		{
			flag1 = false;
			break;
		}
	}
	if (flag1)
	{
		cout << "0";
		return 0;
	}
	if (n == 2)
	{
		if ((s.length() + 1) % 2 == 0)
		{
			if (similar(s))
			{
				cout << s.length()/2+1;
				return 0;
			}
			else
			{
				int a = 0, b = 0;
				bool flag = true;
				for (int i = 1; i < s.length(); i++)
				{
					if (s[i] == s[i-1])
					{
						if (flag)
						{
							a++;
						}
						else
						{
							b++;
						}
					}
					else if(s[i] != s[i - 1])
					{
						flag = false;
					}
				}
				if (a < b)
				{
					cout << a;
				}
				else
				{
					cout << b;
				}
			}
		}
	}
	return 0;
}