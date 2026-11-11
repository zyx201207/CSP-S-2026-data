#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	bool a1,a2;
	getline(cin,c1);
	getline(cin,s1);
	getline(cin,c2);
	getline(cin,s2);
	if(c1==c2&&c1!="01"&&c1!="16")
	cout<<'1';
	else
	{
		cout<<"0000";
		return 0;
	}
	
	if(s1[0]==s2[0]&&s1[1]==s2[1])
	cout<<'1';
	else
	{
		cout<<"000";
		return 0;
	}
	
	if(s1[2]=='D'||s1[2]=='F')
	a1=1;
	else
	a1=0;
	
	if(s2[2]=='D'||s2[2]=='F')
	a2=1;
	else
	a2=0;
	
	if(a1==a2)
	{
		cout<<'1';
		if(s1[2]=='A'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='A')
		cout<<'0';
		else
		cout<<'1';
	}
	else
	cout<<"00";
	
	return 0;
}
