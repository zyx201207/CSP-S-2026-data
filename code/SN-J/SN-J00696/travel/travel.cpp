//陈宇轩 西安市第八十九中学 SN-J00696 
#include <bits/stdc++.h>
using namespace std;
long long n,x;
string m,y;
long long a[1000005];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> n >> m >> x >> y;
	if (n==x)
	{
		cout << "1";
		if (m[1]==y[1] && m[0]==y[0])
		{
			cout << "1";
			if ((m[2]=='A' && y[2]=='B')||(m[2]=='A' && y[2]=='C')||(m[2]=='B' && y[2]=='A')||(m[2]=='B' && y[2]=='C')||(m[2]=='C' && y[2]=='A')||(m[2]=='C' && y[2]=='B')||(m[2]=='D' && y[2]=='E')||(m[2]=='E' && y[2]=='D'))
			{
				cout << "1";
				if ((m[2]=='A' && y[2]=='B')||(m[2]=='B' && y[2]=='A')||(m[2]=='B' && y[2]=='C')||(m[2]=='C' && y[2]=='B')||(m[2]=='D' && y[2]=='E')||(m[2]=='E' && y[2]=='D'))
				{
					cout << "1";
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
