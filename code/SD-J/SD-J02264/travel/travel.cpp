#include<bits/stdc++.h>
using namespace std;

string c1, c2, s1, s2, ans;

int pzw(char n)
{
	if(n == 'A' || n == 'B' || n == 'C')return 0;
	return 1;
}

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2)
	{
		ans += "1";
		int f = 1;
		for(int i = 0; i < 2; i++)
		{
			if(s1[i] != s2[i])
			{
				ans += "000";
				f = 0;
				break;
			}
		}
		if(f == 1)
		{
			ans += "1";
			if(pzw(s1[2]) == pzw(s2[2]))
			{
				ans += "1";
				if(abs(s1[2] - s2[2]) == 1)ans += "1";
				else ans += "0"; 
			}
			else ans += "00";
		}
	}
	else
	{
		ans += "0000";
	}
	cout << ans;
	
	return 0;
} 
