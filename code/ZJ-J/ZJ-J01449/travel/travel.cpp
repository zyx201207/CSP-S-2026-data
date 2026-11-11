#include<bits/stdc++.h>
using namespace std;
string s[7],t[7],ans;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s[1]>>s[2]>>t[1]>>t[2];
	if(s[1]==t[1]) ans+='1';
	else 
	{
		cout<<"0000";
		return 0;
	}
	if(s[2][0]==t[2][0]&&s[2][1]==t[2][1]) ans+='1';
	else 
	{
		cout<<"1000";
		return 0;
	}
	if((s[2][2]=='A'||s[2][2]=='B'||s[2][2]=='C')&&(t[2][2]=='A'||t[2][2]=='B'||t[2][2]=='C')||(s[2][2]=='D'||s[2][2]=='F')&&(t[2][2]=='D'||t[2][2]=='F')) ans+='1';
	else 
	{
		cout<<"1100";
		return 0;
	}
	bool ok=1;
	if(s[2][2]=='D'&&t[2][2]=='F'||s[2][2]=='F'&&t[2][2]=='D'||s[2][2]=='C'&&t[2][2]=='B')
	{
		ans+='1';
		ok=0;
	}
	if(s[2][2]!='D'&&s[2][2]!='F'&&s[2][2]!='C')
	{
		if(s[2][2]+1==t[2][2]||s[2][2]-1==t[2][2])
		{
			ans+='1';
			ok=0;
		}
	}
	if(ok==1)
	{
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
}
