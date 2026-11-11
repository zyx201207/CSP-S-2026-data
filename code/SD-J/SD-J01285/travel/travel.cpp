#include<bits/stdc++.h>
using namespace std;
string ans;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	string l1=s1;
	string l2=s2;
	l1.erase(2,3);
	l2.erase(2,3);
	if(c1==c2)
	{
		if(l1==l2)
		{
			if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')||(s1[2]=='A'&&s2[2]=='B')||(s1[2]=='A'&&s2[2]=='C')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B'))
			{
				if((s1[2]=='C'&&s2[2]=='A')||(s1[2]=='A'&&s2[2]=='C'))
				{
					ans="1110";
				}
				else
				{
					ans="1111";
				}
			}
			else
			{
				ans="1100";
			}
		}
		else
		{
			ans="1000";
		}
	}
	else
	{
		ans="0000";
	}
	cout<<ans;
	return 0;
}

