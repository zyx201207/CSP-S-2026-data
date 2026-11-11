#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define PII pair <int, int>
const int N = 2e5 + 10;

map <char, int> mp;
signed main ()
{
	freopen ("travel.in","r", stdin);
	freopen ("travel.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);  cout.tie(0);
	
	mp['A'] = 0;
	mp['B'] = 0;
	mp['C'] = 0;
	mp['D'] = 1;
	mp['E'] = 1;
	
	string c1, s1, c2, s2;
	
	cin >> c1 >> s1 >> c2 >> s2;
	
	string ans = "";
	if (c1 == c2)
	{
		ans += '1';
	}
	else
	{
		ans += '0';
	}
	
	if (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1])
	{
		ans += '1';
	}
	else
	{
		ans += '0';
	}
	
	if (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && mp[s1[2]] == mp[s2[2]])
	{
		ans += '1';
	}
	else
	{
		ans += '0';
	}
	
	if (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && mp[s1[2]] == mp[s2[2]])
	{
		if ((s1[2] == 'A' && s2[2] == 'C') || (s1[2] == 'C' && s2[2] == 'A'))
		{
			ans += '0';
		}
		else
		{
			ans += '1';
		}
	}
	else
	{
		ans += '0';
	}
	
	cout << ans;
	return 0;
}

/*

02 01A 02 01B

02 01C 02 01A

02 01C 02 01D

02 02B 02 01A

02 01A 03 01A

*/
