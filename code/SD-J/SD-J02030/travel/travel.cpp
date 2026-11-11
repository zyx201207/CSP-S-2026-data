#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,a1,a2;
	cin>>s1>>a1>>s2>>a2;
	if(s1==s2) cout<<"1";
	else
	{
		cout<<"0000";
		return 0;
	}
	if(a1[0]==a2[0] && a1[1]==a2[1]) cout<<"1";
	else
	{
		cout<<"000";
		return 0;
	}
	if(a1[2]<='C' && a2[2]<='C')
	{
		cout<<"1";
		if((a1[2]=='A'&&a2[2]=='C') || (a1[2]=='C'&&a2[2]=='A')) cout<<"0";
		else cout<<"1";
	}
	if((a1[2]>'C'&&a2[2]<='C') || (a1[2]<='C'&&a2[2]>'C'))
	{
		cout<<"00";
		return 0;
	}
	if(a1[2]>'C' && a2[2]>'C') cout<<"11";
	return 0;
} 
