#include <iostream>
using namespace std;
string c1,s1,c2,s2;
int a,b,c,d;
int m,n;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2)
	{
		a=1;
		if (s1[0]==s2[0] && s1[1]==s2[1])
		{
			b=1;
			if (s1[2]=='A' || s1[2]=='B' || s1[2]=='C') m=1;
			if (s2[2]=='A' || s2[2]=='B' || s2[2]=='C') n=1;
			if (m==n)
			{
				c=1;
				d=1;
				if ((s1[2]=='A' && s2[2]=='C') || (s1[2]=='C' && s2[2]=='A')) d=0;
			}
		}
	}
	cout << a << b << c << d;
	return 0;
}
