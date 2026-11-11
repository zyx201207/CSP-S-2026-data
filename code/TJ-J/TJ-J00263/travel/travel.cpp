#include <iostream>
#include <string>
using namespace std;
string c1, s1, c2, s2, pan = "ABCDF";
int a, b, c, d, is1, is2;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	for (int i = 0;i < 5;i++)
	{
		if (s1[2] == pan[i])
		{
			is1 = i;	
		}
		if (s2[2] == pan[i])
		{
			is2 = i;
		}
	}
	if (c1 == c2)
	{
		a = 1;
		if (s1.substr(0, 2) == s2.substr(0, 2))
		{
			b = 1;
			if ((s1[2] >= 'D' && s2[2] >= 'D') || (s1[2] < 'D' && s2[2] < 'D'))
			{
				c = 1;
				if (max(is2 - is1, is1 - is2) == 1)
				{
					d = 1;
				}
			}
		}
	}
	cout << a << b << c << d;
	return 0;
} 
