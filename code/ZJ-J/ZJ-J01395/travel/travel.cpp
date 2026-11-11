#include<bits/stdc++.h>
using namespace std;
char a[100];
bool b[10];
int main ()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	a[65] = 1;
	a[66] = 1;
	a[67] = 1;
	a[68] = 2;
	a[69] = 2;
	string c1 , s1 , c2 , s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if ( c1 == c2 )
	{
		cout << "1";
		if ( s1[0] == s2[0] && s1[1] == s2[1] )
		{
			cout << "1";
			if ( a[(int)(s1[2])] == a[(int)(s2[2])] )
			{
				cout << "1";
				if ( s1[2] == 'D' ) b[(int)(s1[2]-'A'+2)] = true;
				else b[(int)(s1[2]-'A'+1)] = true;
				if ( s2[2] == 'D' ) b[(int)(s2[2]-'A'+2)] = true;
				else b[(int)(s2[2]-'A'+1)] = true;
				for ( int i = 1; i <= 5; i++ )
				{
					if ( b[i] == true && b[i+1] == true )
					{
						cout << "1";
						return 0;
					}
				}
				cout << "0";
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
}
