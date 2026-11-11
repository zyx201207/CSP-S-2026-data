#include<bits/stdc++.h>
using namespace std;

signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,b1,b2;
	cin>>a1>>b1>>a2>>b2;
	
	bool lr1=0,lr2=0;//0 left
	string s1="",s2="";
	s1+=b1[0];
	s1+=b1[1];
	if(b1[2]=='A' || b1[2]=='B' || b1[2]=='C')lr1=0;
	else lr1=1;
	
	s2+=b2[0];
	s2+=b2[1];
	if(b2[2]=='A' || b2[2]=='B' || b2[2]=='C')lr2=0;
	else lr2=1;
	
	if(a1!=a2)
	{
		cout<<"0000";
		return 0;
	}
	else
	{
		cout<<"1";
		if(s1!=s2)
		{
			cout<<"000";
			return 0;
		}
		else
		{
			cout<<"1";
			if(lr1=lr2)
			{
				cout<<"00";
				return 0;
			}
			else
			{
				cout<<"1";
				if(abs(signed(b1[2]-b2[2]))==1)
				{
					cout<<"1";
				}
				else
				{
					cout<<"0";
				}
			}
		}
	}
}
//Trick||Treat!