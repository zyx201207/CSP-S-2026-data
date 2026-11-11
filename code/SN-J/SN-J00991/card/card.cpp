#include <bits/stdc++.h>
using namespace std;

string a1,b1,a2,b2,c1,c2;
bool f1 = 0,f2 = 0,f3 = 0;

int main ()
{
	freopen("card.in","r",stdin);
	freopen("card .out","w",stdout);
	cin >> a1 >> a2 >> b1 >> b2;
	c1 = a2[0] + a2[1];
	c2 = b2[0] + b2[1];
	if (a1 == b1)
	{
		cout << "1";
		f1 = 1;
	}
	else 
	{
		cout << "0";
		f1 = 0;
	}
	
	
	if (f1 && c1 == c2)
	{
		cout << "1";
		f2 = 1;
	}
	else
	{
		cout << "0";
		f2 = 0;
	} 
	
	if(f2 == 1)
	{
		if (a2[2] == 'A' || a2[2] == 'B' || a2[2] == 'C' && b2[2] == 'A' || b2[2] == 'B' || b2[2] == 'C' || a2[2] == 'D' || a2[2] == 'F' && b2[2] == 'D' || b2[2] == 'F')
		{
			cout << "1";
			f3 = 1;
		}
		else cout << "0";
	}
	else cout << "0";	
	
	if (f3 == 1)
	{
		if (a2[2] == 'A' && b2[2] == 'B' || b2[2] == 'A' && a2[2] == 'B' || a2[2] == 'B' && b2[2] == 'C' || b2[2] == 'C' && a2[2] == 'B' || a2[2] == 'D' && b2[2] == 'F' || b2[2] == 'D' && a2[2] == 'F') 
			cout << "1";
		else cout << "0";
	}
	else cout << "0";
	return 0;
} 
