#include <iostream>
#include <string>
using namespace std;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string ca,cb,sa,sb; 
	cin >> ca >> sa >> cb >> sb;
	if (ca == cb)
	{
		cout << "1";
		if((sa[0] == sb[0]) && (sa[1] == sb[1]))
		{
			cout << "1";
			if ((((sa[2] == 'A' || sa[2] == 'B' || sa[2] == 'C') && (sb[2] == 'A' || sb[2] == 'B' || sb[2] == 'C')) || ((sa[2] == 'D' || sa[2] == 'F') && (sb[2] == 'D' || sb[2] == 'F'))) && (sa[2] != sb[2]))
			{
				cout << "1";
				if (((sa[2] + 1 == sb[2]) || (sa[2] - 1 == sb[2])) || ((sa[2] == 'D' && sb[2] == 'F') || (sb[2] == 'D' && sa[2] == 'F')))
				{
					cout << "1" << endl;
				}
				else
				{
					cout << "0" << endl;
				}
			}
			else
			{
				cout << "00" << endl;
			}
		}
		else
		{
			cout << "000" << endl;
		}
	}
	else
	{
		cout << "0000" << endl;
	}
	return 0;
}