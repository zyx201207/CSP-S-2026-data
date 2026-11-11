// Íõ¿¬ä¿ SN-J00810 
#include <bits/stdc++.h>
using namespace std;
bool ce(string s1,string s2)
{
	if (s1[2] >= 'D' && s2[2] >= 'D' || s1[2] <= 'C' && s2[2] <= 'C')
		return true;
	return false;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,c1,c2;
	cin >> c1 >> s1 >> c2 >> s2;
	bool a = (c1 == c2);
	bool b = (a && s1[0] == s2[0] && s1[1] == s2[1]);
	bool c = (b && ce(s1,s2));
	bool d = (c && abs(s1[2] - s2[2]) == 1);
	cout << a << b << c << d;
	return 0;
}
