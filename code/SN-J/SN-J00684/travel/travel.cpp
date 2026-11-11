//张文硕 西安辅轮中学 SN-J00684 
#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
	{
		cout<<"0000";
	}
	else 
	{
		cout<<"1";
		if(s1[1]!=s2[1])
		{
			cout<<"000";
		}
		else if(s1[3]=='c')
		{
			if(s2[3]=='D')
			{
				cout<<"100";
			}
		}
		else if(s1[3]=='D')
		{
			if(s2[3]=='C')
			{
				cout<<"100";
			}
		}
		else 
		{
			cout<<"11";
			if('s2[3]'-'s1[3]'!=1)
			{
				cout<<"0";
			}
			else
			{
				cout<<"1";
			}
		}
	}
	return 0;
}
