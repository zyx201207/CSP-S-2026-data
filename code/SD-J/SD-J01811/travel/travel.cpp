#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	string s="";
	if(c1[0]-'0'==c2[0]-'0'&&c1[1]-'0'==c2[1]-'0')
	{
		s+='1';
		int s3=s1[0]-'0'*10+s1[1]-'0';
		int s4=s2[0]-'0'*10+s2[1]-'0';
		if(s3==s4)
		{
			s+='1';
			if(s1[2]==s2[2])
			{
				s+='1';
				if(s1[2]-'1'==s2[2]||s2[2]-'1'==s1[2])
				{
					s+='1';
				}
				else
				{
					s+='0';
				}
			}
			else
			{
				s+='00';
			}
		}
		else
		{
			s+="000";
		}
	}
	else
	{
		s+="0000";
	}
	cout<<s[0]-'0'<<s[1]-'0'<<s[2]-'0'<<s[3]-'0';
	return 0;
}
