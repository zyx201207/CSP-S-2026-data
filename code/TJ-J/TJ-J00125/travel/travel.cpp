#include<bits/stdc++.h>
using namespace std;

int br, bx;
string sr,sx;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> br >> sr >> bx >> sx;
	if(br == bx)
	{
		cout << 1;
		if(sr[0] == sx[0] && sr[1] == sx[1])
		{
			cout << 1;
			if(sr[2] == 'A' or sr[2] == 'B' or sr[2] == 'C')
			{
				if(sx[2] == 'A' or sx[2] == 'B' or sx[2] == 'C')
				{
					cout << 1;
					if(sr[2] == 'A' or sr[2] == 'B')
					{
						if(sx[2] == 'A' or sx[2] == 'B')
						{
							cout << 1;
						}
						else
						{
							cout << 0;
						}
					}
					if(sr[2] == 'C' or sr[2] == 'B')
					{
						if(sx[2] == 'C' or sx[2] == 'B')
						{
							cout << 1;
						}
						else
						{
							cout << 0;
						}
					}
				}
				else
				{
					cout << "00";
				}
			}
			else
			{
				if(sx[2] == 'D' or sx[2] == 'F')
				{
					cout << 1;
					cout << 1;
				}
				else
				{
					cout << "00";
				}
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
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
