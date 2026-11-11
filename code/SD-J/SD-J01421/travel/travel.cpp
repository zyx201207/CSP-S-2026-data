#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.in","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else
	{
		cout<<"0000";return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]) cout<<1;
	else{
		cout<<"000";return 0;
	}
	//ABCDF
	if(s1[0]==s2[0]&&s1[1]==s2[1])
	{
		char a=s1[2],b=s2[2];
		if(a=='A')
		{
			if(b=='B') cout<<11;
			else if(b=='C') cout<<10;
			else cout<<"00";
		}
		if(a=='B')
		{
			if(b=='A'||b=='C') cout<<11;
			else cout<<"00";
		}
		if(a=='C')
		{
			if(b=='B') cout<<11;
			else if(b=='A') cout<<10;
			else cout<<"00";
		}
		if(a=='D')
		{
			if(b=='F') cout<<11;
			else cout<<"00";
		}
		if(a=='f')
		{
			if(b=='D') cout<<11;
			else cout<<"00";
		}
	}
	return 0;
 } 
