//王子政 SN-J00825 西安市益新中学
#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin >> a >> b >> c >> d;
	string a3,a4;
	char a1,a2;
	a1=b[2];
	a2=d[2];
	a3=b[0]+b[1];
	a4=d[0]+d[1];
	if (a==c)
	{
		cout << 1;
		if (a3==a4)
		{
			cout << 1;
			if (a1=='A'&&a2=='B')
			{
				cout << 1 << 1;
			}
			else if (a1=='A'&&a2=='C')
			{
				cout << 1 << 0;
			}
			else if (a1=='B'&&a2=='A')
			{
				cout << 1 << 1;
			}
			else if (a1=='B'&&a2=='C')
			{
				cout << 1 << 1;
			}
			else if (a1=='C'&&a2=='B')
			{
				cout << 1 << 1;
			}
			else if (a1=='C'&&a2=='A')
			{
				cout << 1 << 0;
			}
			else if (a1=='D'&&a2=='E')
			{
				cout << 1 << 1;
			}
			else if (a1=='E'&&a2=='D')
			{
				cout << 1 << 1;
			}
			else
			{
				cout << 0 << 0;
			}
		}
		else
		{
			cout << 0 << 0 << 0;
			return 0;
		}
	}
	else
	{
		cout << 0 << 0 << 0 << 0;
		return 0;
	}
}
