#include <iostream>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    string a1,b1,b2,a2;
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1)
	{
		cout<<"1";
	    if(a2[0] == b2[0]&&a2[1] == b2[1])
		{
			cout<<"1";
			if(a2[2] == 'C'&&b2[2] == 'D')
			{
				cout<<"00";
			}
			else if(a2[2]=='D'&&b2[2]=='C')
			{
				cout<<"00";
			}
			else
			{
				cout<<"1";
				if(a2[2]=='A'&&b2[2]=='B')
				{
					cout<<"1";
				}
				else if(a2[2]=='B'&&b2[2]=='A')
				{
					cout<<"1";
				}
				else if(a2[2]=='B'&&b2[2]=='C')
				{
					cout<<"1";
				}
				else if(a2[2]=='C'&&b2[2]=='B')
				{
					cout<<"1";
				}
				else if(a2[2]=='D'&&b2[2]=='F')
				{
					cout<<"1";
				}
				else if(a2[2]=='F'&&b2[2]=='D')
				{
					cout<<"1";
				}
				else
				{
					cout<<"0";
				}
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
