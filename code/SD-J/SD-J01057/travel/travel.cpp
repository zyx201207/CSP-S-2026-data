#include<bits/stdc++.h>
using namespace std;

map<char, int> mp;
string ans;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	mp['A'] = 1;
	mp['B'] = 1;
	mp['C'] = 1;
	mp['D'] = 2;
	mp['F'] = 2;
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2) 
	{
		ans += "1";
		bool flag = true;
		for(int i = 0; i < 2; i++)
		{
			if(s1[i] != s2[i])
				flag = false;
		}
		if(flag)
		{
			ans += "1";
			if(mp[s1[2]] == mp[s2[2]])
			{
				ans += "1"; 
				if(abs(s1[2] - s2[2]) == 1 || (s1[2] == 'F' && s2[2] == 'D') || (s1[2] == 'D' && s2[2] == 'F'))
					ans += "1";
				else ans += "0";
			}
			else ans += "00";
		}
		else ans += "000";
	}
	else ans = "0000";
	cout << ans;
	
	return 0;
}//Trick||Treat!
