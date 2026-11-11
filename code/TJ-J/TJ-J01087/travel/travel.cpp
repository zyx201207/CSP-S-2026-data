#include <iostream>
#include <string>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.ans","w",stdout);
	string c1,c2,b1,b2;
	cin>>c1>>c2>>b1>>b2;
	if(c1==b1)
	{
		cout<<"1";
		if((c2[0]==b2[0])&&(c2[1]==b2[1]))
		{
			cout<<"1";
			if(((c2[2]=='A')&&(b2[2]=='B'))||((c2[2]=='B')&&(b2[2]=='A'))||((c2[2]=='B')&&(b2[2]=='A'))||((c2[2]=='B')&&(b2[2]=='C'))||((c2[2]=='D')&&(b2[2]=='E'))||((c2[2]=='E')&&(b2[2]=='D')))
			{
				cout<<"11";
			}
			else if(((c2[2]=='A')&&(b2[2]=='C'))||((c2[2]=='C')&&(b2[2]=='A')))
			{
				cout<<"10";
			}
			else
			{
				cout<<"00";
			}
		}
		else
		{
			cout<<"000";
		}
	}
	else
	{
		cout<<"0000";
	}
	return 0;
}
