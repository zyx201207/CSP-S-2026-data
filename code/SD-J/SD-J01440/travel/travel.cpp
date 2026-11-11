#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(b[0]==d[0] and b[1]==d[1])
	{
		cout<<1;
		if((char(d[2])<='C' and char(b[2])<='C') or(char(d[2])>'C' and char(b[2])>'C'))
		{
			cout<<1;
			if(abs(char(d[2])-char(b[2]))==1)
			{
				cout<<1;
			}
			else
			{
				cout<<0;
			}
		}
		else
		{
			cout<<0;
		}
	}
	else
	{
		cout<<0<<0<<0;
	}
	
	return 0;
}
