#include <iostream>
using namespace std;
int f,g; 
string r,x;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> f >> r >> g >> x;
	if(f == g)
	{
		cout << "1";
		if(r[0] == x[0] && r[1] == x[1])
		{
			cout << "1";
			char w = r[2],e = x[2];
			if((w == 'A' || w == 'B' || w == 'C') && (e == 'A' || e == 'B' || e == 'C') || (w == 'F' || w == 'D') && (e == 'F' || e == 'D'))
			{
				cout << "1";
				if((w == 'B' || e == 'B') || (w == 'D' || e == 'D'))
				{
					cout <<  "1"; 
				}
				else 
				{
					cout << "0";
				}
			}
			else
			{
				cout << "00";
			}
		} 
		else
		{
			cout << "000";
		}
	}
	else
	{
		cout << "0000";
	}
	return 0;
 } 
