#include <bits/stdc++.h>
using namespace std;
int a1,a2,b1,b2;
char a,b;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>a>>b1>>b2>>b;
	if(a1 == b1)
	{
		cout<<'1';
		if(a2 == b2)
		{
			cout<<'1';
			if((a <= 'C' && b <= 'C') || (a > 'C' && b > 'C'))
			{
				cout<<'1';
				if((a == 'A' && b == 'B') || (a == 'B' && b == 'A'))
					cout<<'1';
				else if((a == 'B' && b == 'C') || (a == 'C' && b == 'B'))
					cout<<'1';
				else if((a == 'D' && b == 'F') || (a == 'F' && b == 'D'))
					cout<<'1';
				else cout<<'0';
			}
			else
				cout<<"00";
		}
		else
			cout<<"000";
	}
	else
		cout<<"0000";
	return 0;
}
