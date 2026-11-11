#include <bits/stdc++.h>
using namespace std;
string c_1, c_2, s_1, s_2;
map<char, int> mp;
map<pair<char, char>, bool> m;
signed main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c_1 >> s_1 >> c_2 >> s_2;
	if(c_1 != c_2)
	{
		cout << "0000\n";
		return 0;
	}
	if(s_1[0] + s_1[1] != s_2[0] + s_2[1])
	{
		cout << "1000\n";
		return 0;
	}
	mp['A'] = mp['B'] = mp['C'] = 1;
	mp['D'] = mp['F'] = 2;
	if(mp[s_1[2]] != mp[s_2[2]])
	{
		cout << "1100\n";
		return 0;
	}
	m[{'A', 'B'}] = m[{'B', 'A'}] = m[{'B', 'C'}] = m[{'C', 'B'}] = m[{'D', 'F'}] = m[{'F', 'D'}] = 1;
	if(!m[{s_1[2], s_2[2]}])
	{
		cout << "1110\n";
		return 0;
	}
	cout << "1111\n";
	return 0;
}
