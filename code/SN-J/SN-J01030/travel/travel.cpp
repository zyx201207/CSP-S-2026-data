#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	string c1, s1, c2, s2;
	
	cin >> c1 >> s1 >> c2 >> s2;
	
	int num1 = (s1[2] - 64);
	int num2 = (s2[2] - 64);
	
	if(num1 > num2)
	{
		swap(num1, num2);
	}
	
	if(c1 == c2)
	{
		cout << "1";
	
		if(s1[0] == s2[0] and s1[1] == s2[1])
		{
			cout << "1";
			
			if(num1 >= 4 or num2 <= 3)
			{
				cout << "1";
				
				if(num2 - num1 == 1)
				{
					cout << "1";
				}
				else
				{
					cout << "0";
				}
			}
			else
			{
				cout << "00";
			}
		}
		else
		{
			cout << "000";
		}
	}
	else
	{
		cout << "0000";
	}
	
	return 0;
}
