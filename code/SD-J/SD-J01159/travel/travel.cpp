#include <bits/stdc++.h>
//#define int long long
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	string z = "";
	if (c1 == c2)
	{
		z += '1';
		string x1 = "";
		x1 += s1[0];
		x1 += s1[1];
		string x2 = "";
		x2 += s2[0];
		x2 += s2[1];
		if (x1 == x2)
		{
			z += '1';
			char f1 = s1[2];
			char f2 = s2[2];
			if ((f1 == 'A' || f1 == 'B' || f1 == 'C') && (f2 == 'A' || f2 == 'B' || f2 == 'C'))
			{
				z += '1';
				if ((f1 == 'A' && f2 == 'B') || (f1 == 'B' && f2 == 'A') || (f1 == 'B' && f2 == 'C') || (f1 == 'C' && f2 == 'B'))
				{
					z += '1';
				}
				else
				{
					z += '0';
				}
			}
			else if ((f1 == 'D' || f1 == 'F') && (f2 == 'D' || f2 == 'F'))
			{
				z += "11";
			}
			else
			{
				z += "00";
			}
		}
		else
		{
			z += "000";
		}
	}
	else
	{
		z += "0000";
	}
	cout << z;
	return 0;
}
