#include <bits/stdc++.h>
using namespace std;
string cc1,cc2,ss1,ss2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> cc1 >> ss1 >> cc2 >> ss2;
	int c1,c2,s1,s2,g1,g2;
	char h1,h2;
    c1 = (cc1[0] - '0') * 10 + (cc1[1] - '0');
    c2 = (cc2[0] - '0') * 10 + (cc2[1] - '0');
    s1 = (ss1[0] - '0') * 10 + (ss1[1] - '0');
    s2 = (ss2[0] - '0') * 10 + (ss2[1] - '0');
    h1 = ss1[2];
    h2 = ss2[2];
    if(h1 == 'A' || h1 == 'B' || h1 == 'C')
    {
    	g1 = 1;
	}
	else
	{
		g1 = 2;
	}
	if(h2 == 'A' || h2 == 'B' || h2 == 'C')
    {
    	g2 = 1;
	}
	else
	{
		g2 = 2;
	}
    if(c1 != c2)
    {
    	cout << "0000";
	}
	else if(s1 != s2)
	{
		cout << 1000;
	}
	else if(g1 != g2)
	{
		cout << 1100;
	}
	else if(abs(h1 - h2) != 1)
	{
		cout << 1110;
	}
	else
	    cout << 1111;
	return 0;
}
