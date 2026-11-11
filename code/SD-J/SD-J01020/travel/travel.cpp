#include <bits/stdc++.h>
using namespace std;
char a[5];
char b[5];
char aa[5];
char bb[5];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> aa >> bb;
	if(a[0] != aa[0] || a[1] != aa[1])
	{
		cout << "0000";
		return 0;
	}
	else
	{
		cout << "1";
	}
	
	if(b[0] != bb[0] || b[1] != bb[1])
	{
		cout << "000";
		return 0;
	}
	else
	{
		cout << "1";
	}
	
	if(b[2] <= 'C' && bb[2] >= 'D' || b[2] >= 'D' && bb[2] <= 'C')
	{
		cout << "00";
		return 0;
	}
	else
	{
		cout << "1";
	}
		
	if(b[2] == 'A' && bb[2] == 'B' || b[2] == 'B' && bb[2] == 'C' || b[2] == 'D' && bb[2] == 'F')
	{
		cout << "1";
		return 0;
	}
	else
	{
		cout << "0";
	}
	return 0;
}
