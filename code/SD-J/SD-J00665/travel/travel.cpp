#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen ("travel.in","r",stdin);
	freopen ("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >>c1>>s1>>c2>>s2;
	string ans="";
	string ss1,ss2;
	ss1=s1.substr(0,2);
	ss2=s2.substr(0,2);
	if (c1==c2)
	{
		ans+='1';
		if (ss1==ss2)
		{
			ans+='1';
			if ((s1[2]<='C' && s2[2]<='C'))
			{
				ans+='1';
				if ((s1[2]=='A' && s2[2]=='B') || (s1[2]=='B' && s2[2]=='C') ||(s1[2]=='B' && s2[2]=='A') || (s1[2]=='C'&& s2[2]=='B'))
				{
					ans+='1';
					cout <<ans;
				}
				else
				{
					ans+='0';
					cout <<ans;
				}
				
			}
			else if (s1[2]>='D' && s1[2]>='D')
			{
				ans+="11";
				cout <<ans;
			}
			else
			{
				ans+="00";
				cout <<ans;
			}
		}
		else
		{
			ans+="000";
			cout <<ans;
		}
	}
	else
	{
		ans="0000";
		cout <<ans;
	}
	
	return 0;
}
