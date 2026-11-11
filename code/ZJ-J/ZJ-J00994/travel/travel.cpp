#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string sr1, sr2, sx1, sx2;
	cin >> sr1 >> sr2 >> sx1 >> sx2;
	if(sr1[0] == sx1[0] && sr1[1] == sx1[1])
	{
		cout << '1';
	}
	else
	{
		cout << "0000";
		return 0;
	}
	
	if(sr2[0] == sx2[0] && sr2[1] == sx2[1])
	{
		cout << '1';
		if((sr2[2] <= 'C' && sx2[2] <= 'C') || (sr2[2] > 'C' && sx2[2] > 'C'))
		{
			cout << '1';
			if(abs(sr2[2] - sx2[2]) == 1)
			{
				cout << '1';
			}
			else
			{
				cout << '0';
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
	
	return 0;
}
