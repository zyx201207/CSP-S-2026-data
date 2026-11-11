#include <bits/stdc++.h>
using namespace std;
string co,so,ct,st;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>co>>so>>ct>>st;
	if(co==ct)
	{
		if(so[0]==st[0] && so[1]==st[1])
		{
			if((so[2]=='A'||so[2]=='B'||so[2]=='C')&&(st[2]=='A'||st[2]=='B'||st[2]=='C'))
			{
				if(so[2]-st[2]==1||so[2]-st[2]==-1)
				{
					cout<<"1111";
					return 0;
				}
				else
				{
					cout<<"1110";
					return 0;
				}
			}
			else if((so[2]=='D' || so[2]=='F')&&(st[2]=='D' || st[2]=='F'))
			{
				cout<<"1111";
				return 0;
			}
			else
			{
				cout<<"1100";
				return 0;
			}
		}
		else
		{
			cout<<"1000";
			return 0;
		}
	}
	else
	{
		cout<<"0000";
		return 0;
	}
}
