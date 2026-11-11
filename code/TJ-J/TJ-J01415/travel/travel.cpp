#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string c,d;
	cin >> a >> c >> b >> d;
	if(a!=b)
	{
		cout << "0000";
	}
	else
	{
		char s1=c[0]+c[1];
		char s2=d[0]+d[1];
		if(s1!=s2)
		{
			cout << "1000";
		}
		else
		{
			if ((c[2]<'D'&&d[2]<'D')||(c[2]>'C'&&d[2]>'C'))
			{
				if(c[2]==d[2]+1||c[2]==d[2]-1)
				{
					cout << "1111";
				}
				else
				{
					cout << "1110";
				}
			}
			else
			{
				cout << "1100";
			}
		}
	}
	return 0;
}
