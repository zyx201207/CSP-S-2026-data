#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdin);
	string c1,s1,c2,s2,p[5];
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		p[1]='1';
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0] && s1[1]==s2[1])
	{
		p[2]='1';
	}
	else
	{
		cout<<"1000";
		return 0;
	}
	char a=s1[2];
	char b=s2[2];
	if(a=='D' && b=='F' || a=='F' && b=='D' || a=='A' && b=='B' || b=='A' && a=='B' || a=='B' && b=='C' || b=='A' && a=='B')
	{
		cout<<"1111";
		return 0;
	}
	else if(a=='A' && b=='C' || a=='C' && b=='A')
	{
		cout<<"1110";
		return 0;
	}
	else
	{
		cout<<"1100";
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
}
