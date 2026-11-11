#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int main()
{
	preopen ("travel.in","r",stdin);
	preopen ("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2 && ((c1[1] != '1' && c1[0] != '0' ) || (c1[1] != '1' && c1[1] != '6')))
	{
		cout << 1;
	}
	else
	{
		cout << "0000";
		return 0;
	}
	string n1,n2, m1, m2;
	m1 = s1[2];
	m2 = s2[2];
	for (int i = 0;i <= 1;i++)
	{
		n1 += s1[i];
		n2 += s2[i];
	}
	if (n1[0] == n2[0] && n1[1] == n2[1])
	{
		cout << 1;
		if (m1[0] - 'D'>= 0 && m2[0]-'D' >= 0 && m1 != m2)
		{
			cout << "1";
		}
		else if (m1[0] - 'C' <= 0 && m2[0] - 'C' <= 0 && m1 != m2)
		{
			cout << "1";
		}
		else
		{
			cout << "00";
			return 0;
		}
		if (m1[0] - '0'+ 1 == m2[0] -'0'|| m1[0]-'0'-1==m2[0]-'0' || n1[0]-'0'-1==n2[0]-'0' || n1[0]-'0'+1==n2[0]-'0')
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
		cout << "000";
	}
	return 0;
}
