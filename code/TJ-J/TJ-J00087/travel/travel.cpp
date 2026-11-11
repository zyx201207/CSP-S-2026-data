#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	string str;
	getline(cin, str);
	bool box = true, row = true, line = true, beside = false;
	for (int i = 0; i < 6; i++)
	{
		if (i < 2)
		{
			if (str[i] != str[i + 7])
			{
				box = false;
			}
		}
		else if (i < 5)
		{
			if (!box)
			{
				row = false;
				line = false;
				break;
			}
			else
			{
				if (str[i] != str[i + 7])
				{
					row = false;
					line = false;
					break;
				}
			}
		}
		else
		{
			if (!((str[i] <= 'C' && str[i + 7] <= 'C') || (str[i] >= 'D' && str[i + 7] >= 'D')))
			{
				line = false;
			}
			else
			{
				if (str[i] <= 'C' && str[i + 7] <= 'C')
				{
					if (str[i] == str[i + 7] + 1 || str[i] + 1 == str[i + 7])
					{
						beside = true;
					}
				}
				else
				{
					if (str[i] == str[i + 7] + 2 || str[i] + 2 == str[i + 7])
					{
						beside = true;
					}
				}
			}
		}
	}
	cout << ((box)? "1" : "0") << ((row)? "1" : "0") << ((line)? "1" : "0") << ((beside)? "1" : "0");
	return 0;
}

/*
seat27
*/
