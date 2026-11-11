#include <bits/stdc++.h>
using namespace std;
char xa,xb,xc,ya,yb,yc;
int a,b;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>xa>>xb>>xc>>b>>ya>>yb>>yc;
	if (a==b)
	{
		cout<< "1";
	}
	else
	{
		cout << "0000";
		return 0;
	}
	if (xa == ya && xb == yb)
	{
		cout<< "1";
	}
	else
	{
		cout << "000";
		return 0;
	}
	if ((xc < 'D' && yc < 'D') || (xc > 'C' && yc > 'C'))
	{
		cout<< "1";
		
	}
	else
	{
		cout << "00";
		return 0;
	}
	if (xc + 1 == yc || xc - 1 == yc)
	{
		cout << "1";
	}
	else
	{
		cout << "0";
	}
}

