#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout); 
	string numR, numX, sR, sX;
	cin >> numR >> sR >> numX >> sX;
	if (numR == numX)
	{
		cout << "1";
		if (sR[0] == sX[0] && sR[1] == sX[1])
		{
			cout << "1";
			if ((sR[2] <= 'C' && sX[2] <= 'C') || (sR[2] >= 'D' && sX[2] >= 'D'))
			{
				cout << "1";
				if (abs(sR[2] - sX[2]) == 1) cout << "1";
				else cout << "0";
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
 } 
