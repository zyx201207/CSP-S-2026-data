#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1;
	cin >> s1;
	cin >> c2;
	cin >> s2;
	char s = s1[2],ss = s2[2];
	if (c1 == c2) cout << '1';
	else cout << '0';
	if (c1 == c2 && (s1[0] == s2[0] && s1[1] == s2[1])) cout << '1';
	else cout << '1';
	if (c1 == c2 && (s1[0] == s2[0] && s1[1] == s2[1]) && (s >= 'A' && s <= 'C' && ss >= 'A' && ss <= 'C'))
	{
		cout << '1';
	}
	else if (c1 == c2 && (s1[0] == s2[0] && s1[1] == s2[1]) && ((s == 'D' && ss == 'F') || (s == 'F' && ss == 'D')))
	{
		cout << '1';
	}
	else cout << '0';
	if (c1 == c2 && (s1[0] == s2[0] && s1[1] == s2[1]) && (s >= 'A' && s <= 'C' && ss >= 'A' && ss <= 'C')&&
	(s-ss == 1 || ss - s == 1))
	{
		cout << '1';
	}
	else if (c1 == c2 && (s1[0] == s2[0] && s1[1] == s2[1]) && ((s == 'D' && ss == 'F') || (s == 'F' && ss == 'D')))
	{
		cout << '1';
	}
	else cout << '0';
	return 0;
}
