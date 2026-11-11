#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,p1,p2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	p1=s1[0];
	p1+=s1[1];
	p2=s2[0];
	p2+=s2[1];
	if(c1!=c2)
	{
		cout<<"0000";
	}
	else
	{
		cout<<"1";
		if(p1!=p2)
		{
			cout<<"000";
		}
		else
		{
			cout<<"1";
			if((s1[2]=='D'&&s2[2]=='F')||(s2[2]=='D'&&s1[2]=='F'))
			{
				cout<<"11";
			}
			else if(s1[2]!='D'&&s1[2]!='F'&&s2[2]!='D'&&s2[2]!='F')
			{
				cout<<"1";
				if((s1[2]=='A'&&s2[2]=='C')||(s2[2]=='A'&&s1[2]=='C'))
				{
					cout<<"0";
				}
				else
				{
					cout<<"1";
				}
			}
			else
			{
				cout<<"00";
			}
		}
	}
	return 0;
}
