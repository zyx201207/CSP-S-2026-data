#include <iostream>
using namespace std;
int main()
{
	int c1,c3;
	string c2,c4,cc2[3],cc4[3];
	cin >> c1 >> c2 >> c3 >> c4;
	for (int i = 1; i <= 3; i++)
	{
		cc2[i] = c2;
		cc4[i] = c4;
	}
	if (c1 == c3)
	{
		cout << 1;
		if (cc2[1] == cc4[1])
		{
			if (cc2[2] == cc4[2])
			{
				cout << 1;
				if ((cc2[3] == 'A' || cc2[3] == 'B' || cc2[3] == 'C') && (cc4[3] == 'A' || cc4[3] == 'B' || cc4[3] == 'C'))
				{
					cout << 1;
					if ((cc2[3] == 'A' || cc2[3] == 'B') && (cc4[3] == 'A' || cc4[3] == 'B'))
					{
						cout << 1;
					}
					else if ((cc2[3] == 'B' || cc2[3] == 'C') && (cc4[3] == 'B' || cc4 == 'C'))
					{
						cout << 1;
					}
					else 
					{
						cout << 0;
					}
				}
				else if ((cc2[3] == 'D' || cc2[3] == 'E') && (cc4[3] == 'D' || cc4[3] == 'E'))
				{
					cout << 11;
				}
				else
				{
					cout << 00;
				}
			}
		}
		else
		{
			cout << 000;
		}
	}
	else
	{
		cout << 0000;
	}
	return 0;
}