#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,n1;
	string s2,n2;
	cin>>s1;
	cin>>n1;
	cin>>s2;
	cin>>n2;
	if(s1==s2)
	{
		if(s1!="01" && s1!="16" && s2!="01" && s2!="16")
		{
			cout<<1;
		}
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if(n1[0]==n2[0] && n1[1]==n2[1])
	{
		cout<<1;
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if(n1[2]=='A' || n1[2]=='B' || n1[2]=='C' && n2[2]=='A' || n2[2]=='B' || n2[2]=='C' && n1[0]==n2[0] && n1[1]==n2[1])
	{
		cout<<1;
	}
	else if(n1[2]=='D' || n1[2]=='F' && n2[2]=='D' || n2[2]=='F' && n1[0]==n2[0] && n1[1]==n2[1])
	{
		cout<<1;
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if(int(n1[2])+1==int(n2[2]) || int(n1[2])-1==int(n2[2]))
	{
		if(n1[2]=='A' || n1[2]=='B' || n1[2]=='C' && n2[2]=='A' || n2[2]=='B' || n2[2]=='C')
		{
			cout<<1;
		}
		else if(n1[2]=='D' || n1[2]=='F' && n2[2]=='D' || n2[2]=='F')
		{
			cout<<1;
		}
	}
	else
	{
		cout<<0;
	}
	return 0;
}
