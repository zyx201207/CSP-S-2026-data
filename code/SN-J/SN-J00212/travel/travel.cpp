#include <bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("travel.in","cin",stdin);
	//freopen("travel.in","cout",stdout);
	int c1,c2,r1,r2;
	char s1,s2;
	cin>>c1>>r1>>s1>>c2>>r2>>s2;
	if(c1==c2)
		cout<<"1";
	else
	{
		cout<<"0000";
		return 0;
	}
	if(r1==r2)
		cout<<"1";
	else
	{
		cout<<"000";
		return 0;
	}	
	if((s1>='A' && s1<='C') && (s2>='A' && s2<='C'))
	{
		cout<<"1";
		if((s1=='A' || s1=='C') && (s2=='A' || s2=='C'))
			cout<<"0";
		else
			cout<<"1";
	}
	else if((s1>='D' && s1<='F') && (s2>='D' && s2<='F'))
	{
		cout<<"11";
		return 0;
	}
	else
	{
		cout<<"00";
		return 0;
	}
	return 0;
}      
