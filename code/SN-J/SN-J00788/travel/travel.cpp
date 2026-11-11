// SN-J0078 杨佳锐 西安交通大学附属中学兴庆校区 
#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
//	freopen("travel.in","r","std.in");
//	freopen("travel.out","w","std.out");
	cin>>c1>>s1>>c2>>s2;
	if (c1==c2)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
 	if (s1[1]==s2[1] )
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if ((s1[2]=='A' || s1[2]=='B' || s1[2]=='C') && (s2[2]=='A' || s2[2]=='B' ||s2[2]=='C'))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if ((s1[2]=='A' && s2[2]=='B') || (s1[2]=='B' && s2[2]=='C') || (s1[2]=='D' || s2[2]=='F'))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
