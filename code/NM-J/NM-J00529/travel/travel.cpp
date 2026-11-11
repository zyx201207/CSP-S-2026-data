#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s="",c1,s1,c2,s2,x,y; 
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) 
	{
		s+='1';
		x=s1[0]+s1[1];
		y=s2[0]+s2[1];
		if(x==y) s+='1';
		else s+='0';
		if(x==y)
		{
			if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')) s+='1';
			else if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')) s+='1';
			else s+='0';
		}
		else s+='0';
		if(x==y)
		{
			if(s1[2]=='A'&&s2[2]=='B') s+='1';
			else if(s1[2]=='B'&&s2[2]=='A') s+='1';
			else if(s1[2]=='B'&&s2[2]=='C') s+='1';
			else if(s1[2]=='C'&&s2[2]=='B') s+='1';
			else if(s1[2]=='D'&&s2[2]=='F') s+='1';
			else if(s1[2]=='F'&&s2[2]=='D') s+='1';
			else s+='0';
		}
		else s+='0';
	}
	else s+="0000";
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
