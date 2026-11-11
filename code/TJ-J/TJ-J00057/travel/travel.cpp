#include <iostream>
using namespace std;
string c1, s1, c2, s2;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	bool fa = (c1 == c2);
	bool fb = (s1[0] + s1[1] == s2[0] + s2[1]);
	bool fc = ((s1[2] == 'A' && s2[2] == 'B') || (s1[2] == 'A' && s2[2] == 'C') || (s1[2] == 'B' && s2[2] == 'A') || (s1[2] == 'B' && s2[2] == 'C') || (s1[2] == 'C' && s2[2] == 'B') || (s1[2] == 'C' && s2[2] == 'A') || (s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D'));
	bool fd = (fa && fb && fc && ((s1[2] == 'A' && s2[2] == 'B')||(s1[2] == 'B' && s2[2] == 'A') || (s1[2] == 'B' && s2[2] == 'C') || (s1[2] == 'C' && s2[2] == 'B') || (s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D')));
	if(fa)
	{
		cout << "1";
	}
	else
	{
		cout << "0";
	}
	if(fa && fb)
	{
		cout << "1";
	}
	else
	{
		cout << "0";
	}
	if(fa && fb && fc)
	{
		cout << "1";
	}
	else
	{
		cout << "0";
	}
	if(fd)
	{
		cout << "1";
	}
	else
	{
		cout << "0";
	}
	return 0;
} 
