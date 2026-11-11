#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int cnt=0,num=0;
int main()
{
	//freopen("travel.in","r","stdin");
	//freopen("travel.out","w","stdout");
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2) 
	{
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(s1[0]+s1[1]!=s2[0]+s2[1])
	{
		cout<<"000";
		return 0;
	}
	cout<<1;
	if(s1[2]=='A' || s1[2]=='B' || s1[2]=='C' && s2[2]=='A' || s2[2]=='B' || s2[2]=='C')
	{
		cnt=1;
	}
	else if(s1[2]=='D' || s1[2]=='E' && s2[2]=='D' || s2[2]=='E')
	{
				cnt=1;
	}
	if(cnt==0)
	{
			cout<<"00";
			return 0;
	}
    cout<<1;
	if(s1[2]=='A' && s2[2]=='B' || s1[2]=='B' && s2[2]=='C' || s1[2]=='B' && s2[2]=='A' || s1[2]=='C' && s2[2]=='B')
	{
		num=1;
	}
	else if(s1[2]=='D' && s2[2]=='E' || s1[2]=='D' && s2[2]=='E' )
	{
		num=1;
	}
	if(num==0)
	{
		cout<<0;
		return 0;
	}
	cout<<1;
	return 0;
}
