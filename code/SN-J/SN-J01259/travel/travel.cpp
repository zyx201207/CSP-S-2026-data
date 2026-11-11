#include <bits/stdc++.h>
using namespace std;
int rc1,xc1,rc2,xc2;
char rs,xs;
bool a = 0,b = 0;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> rc1 >> rc2 >> rs >> xc1 >> xc2 >> xs;
	cout << (rc1 == xc1);
    cout << ((rc2 == xc2)&& (rc1 == xc1));
    if(rs == 'A' || rs == 'B' || rs == 'C')
    {
    	if(xs == 'A' || xs == 'B' || xs == 'C')
    	{
    		a = 1;
		}
	}
	else
	{
		if(xs == 'D' || xs == 'F')
    	{
    		a = 1;
		}
	}
	cout << (a && (rc2 == xc2) && (rc1 == xc1));
	cout << (a && (rs == xs + 1 || xs == rs + 1) && (rc2 == xc2) && (rc1 == xc1));
	return 0;
}
