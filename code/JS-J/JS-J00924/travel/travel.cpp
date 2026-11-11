#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2)
	{
		cout << 1;
		char l = s1[0] + s1[1],l2 = s2[0] + s2[1];
		if(l == l2)
		{
			cout << 1;
			char z = s1[2],z2 = s2[2];
			if(max(z - z2,z2 - z) <= 2)
			{
				if((z == 'C' && z2 == 'D') || (z == 'D' && z2 == 'C'))
				{
					cout << "00";
					return 0;
				}
				cout << 1;
				if(max(z - z2,z2 - z) == 1 || (max(z - z2,z2 - z) == 2 && ((z == 'D' && z2 == 'F') || (z == 'F' && z2 == 'D'))))
				{
					cout << 1;
				}
				else
				{
					cout << 0;
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
	fclose(stdin);
	fclose(stdout);
	return 0;
}
