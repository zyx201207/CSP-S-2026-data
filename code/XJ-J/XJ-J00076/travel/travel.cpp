#include <bits/stdc++.h>
using namespace std;
int c1,c2,a[25][25];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int s1,s2;
	char n1,n2;
	cin >> c1 >> s1>> n1 >> c2 >>s2 >> n2;
	if (c1 == c2)
	{
		if (s1 == s2)
		{
			if (n1-'0'== n2-'0'+1)
			{
				cout << "1111";
			}
			else
			{
				cout << "1100";
			}
		}
		else
		{
			cout  << "1000"; 
		}
	}
	else
	{
		cout << "0000";
	}
	return 0;
 } 
