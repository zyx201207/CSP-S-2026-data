#include <iostream>
#include <string>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if (c1=="01" || c2=="01" || c1=="16" || c2=="16" || c1!=c2)
	{
		cout<<"0000";
	}
	else
	{
		if (s1[0,1]!=s2[0,1])
		{
			cout<<"1000";
		}
		else
		{
			if ((s1[2]=='A' && s2[2]=='B') || (s1[2]=='A' && s2[2]=='C') || (s1[2]=='B' && s2[2]=='C') || (s1[2]=='D' && s2[2]=='F'))
			{
				if ((s1[2]=='A' && s2[2]=='B') || (s1[2]=='B' && s2[2]=='C') || (s1[2]=='D' && s2[2]=='F'))
				{
					cout<<"1111";
				}
				else
				{
					cout<<"1110";
				}
			}
			else
			{
				cout<<"1100";
			}
		}
	}
	return 0;
}
