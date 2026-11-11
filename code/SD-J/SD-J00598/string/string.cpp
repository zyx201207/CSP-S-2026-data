#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a = 0;
	long long y = 0;
	bool x = 1;
	string b,s = "";
	
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a;
		if(i == 2)
		{
			y = a;
		}
		cin >> b;
		for(int j = 1;j <= a;j++)
		{
			s += a;
		}
	}
	
	for(int i = 1;i < s.length();i++)
	{
		if(s[i-1] != s[i])
		{
			x = 0;
		}
		else 
		{
			for(int i = 0;i <= s.length() / 2;i++)
			{
				for(int j = s.length();j >= s.length() / 2;j--)
				{
					if(s[i] != s[i-1])
					{
						x = 0;
					}
				}
			}
		}
	}
	if(x == 0)
	{
		cout << 0;
	}
	else
	{
		cout << y;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
