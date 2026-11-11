#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string  c1, s1, c2, s2;
	cin>>c1>>s1>>c2>>s2;
	char s[4];
	char sl[4];
	for(int i=0; i<3; i++)
	{
		s[i]=s1[i];
		sl[i]=s2[i];
	}
	if(c1==c2)
	{
		cout<<"1"<<" ";
	}
	else
	{
		cout<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0";
		return 0;
	}
	if(s[0]==sl[0]&&s[1]==sl[1])
	{
		cout<<"1"<<" ";	
	}
	else
	{
		cout<<"0"<<" "<<"0"<<" "<<"0";
		return 0;
	}
	if(s[2]=='B'&&sl[2]=='C'||s[2]=='C'&&sl[2]=='B'||s[2]=='A'&&sl[2]=='B'||s[2]=='B'&&sl[2]=='A'||s[2]=='A'&&sl[2]=='C'||s[2]=='C'&&sl[2]=='A'||s[2]=='D'&&sl[2]=='F'||s[2]=='F'&&sl[2]=='D')
	{
		cout<<"1"<<" ";
}
	else
	{
		cout<<"0"<<" "<<"0";
		return 0;
	}
	if(s[2]=='B'&&sl[2]=='C'||s[2]=='C'&&sl[2]=='B'||s[2]=='A'&&sl[2]=='B'||s[2]=='B'&&sl[2]=='A'||s[2]=='D'&&sl[2]=='F'||s[2]=='F'&&sl[2]=='D')
	{
		cout<<"1";	
	}
	else
	{
		cout<<"0";
		return 0;
	}
	
	return 0;
}