#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen ("travel.in","r",stdin);
	freopen ("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	char a = s1[2];
	char b = s2[2];
	if (c1 == c2)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	if (s1[0] == s2[0] && s1[1] == s2[1])
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	if ((a == 'A' && b == 'B') || (a == 'A' && b == 'C'))
	{
		cout << 1;
	}
	else if ((a == 'B' && b == 'A') || (a == 'B' && b == 'C'))
	{
		cout << 1;
	}
	else if ((a == 'C' && b == 'A') || (a == 'C' && b == 'B'))
	{
		cout << 1;
	}
	else if ((a == 'D' && b == 'F') || (a == 'F' && b == 'D'))
	{
		cout << 1;
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	if ((a == 'A' && b == 'B') || (a == 'B' && b == 'A') || (a == 'B' && b == 'C') || (a == 'C' && b == 'B'))
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	return 0;
}
