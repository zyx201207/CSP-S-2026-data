#include <bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4,s;
int main()
{
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>s1>>s2>>s3>>s4;

	if(s1==s3)
	{
		s+='1';
	}
	else s+='0';
	if(s2[0]==s4[0]&&s2[1]==s4[1]&&s[0]=='1')
	{
		s+='1';
	}
		else s+='0';
	if(((s2[2]=='A'&&(s4[2]=='B'||s4[2]=='C'))||(s2[2]=='B'&&(s4[2]=='A'||s4[2]=='C'))||(s2[2]=='C'&&(s4[2]=='B'||s4[2]=='A')))&&s[1]=='1')
	{
	s+='1';
	}
		else s+='0';
	if((s2[2]+1==s4[2]||s2[2]-1==s4[2])&&s[2]=='1')
	{
	s+='1';
	}
	else s+='0';
	cout<<s;
	return 0;
 } 
