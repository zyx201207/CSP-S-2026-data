#include <bits/stdc++.h>
using namespace std;

string c1, c2, s1, s2;
string str1, str2;
char a, b;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin >> c1;
	cin >> s1;
	cin >> c2;
	cin >> s2;
	
	if (c1 != c2)
	{
		cout << "0000";
		return 0;
	}
	
	cout << 1;
	
	str1 = s1.substr(0, 2), str2 = s2.substr(0, 2);
	
	if (str1 != str2)
	{
		cout << "000";
		return 0;
	}
	
	cout << 1;
	
	
	if ((s1[2] == 'C' && s2[2] == 'D') || (s1[2] == 'D' && s2[2] == 'C'))
	{
		cout << "00";
		return 0;
	}
	
	cout << 1;
	
	if (s1[2] < 'D' && s2[2] < 'D' && abs(s1[2] - s2[2]) == 1)
		cout << 1;
	else if ((s1[2] == 'F' || s2[2] == 'F') && abs(s1[2] - s2[2]) == 2)
		cout << 1;
	else 
		cout << 0;
	
	return 0;
}