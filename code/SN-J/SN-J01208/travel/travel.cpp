#include <iostream>
#include <cmath>
#include <cstdio>
#include <map>

using namespace std;
string c1, s1, c2, s2;
map <char, int> m;
int train_number1, train_number2, set1, set2;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	m['A'] = m['B'] = m['C'] = 1;
	set1 = (int)(s1[0] - '0') * 10 + (int)(s1[1] - '0');
	set2 = (int)(s2[0] - '0') * 10 + (int)(s2[1] - '0');
	train_number1 = (int)(c1[0] - '0') * 10 + (int)(c1[1] - '0');
	train_number2 = (int)(c2[0] - '0') * 10 + (int)(c2[1] - '0');
	if (train_number1 != train_number2)
	{
		cout << "0000\n";
	}
	else
	{
		if (set1 != set2)
		{
			cout << "1000\n";
		}
		else
		{
			if (m[s1[2]] != m[s2[2]])
			{
				cout << "1100\n";
			}
			else
			{
				if (abs(s1[2] - s2[2]) == 1)
				{
					cout << "1111\n";
				}
				else
				{
					cout << "1110\n";
				}
			}
		}
	}
	return 0;
}
