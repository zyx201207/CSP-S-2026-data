#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,b1,a2,b2;
	cin>>a1>>b1>>a2>>b2;
	if(a1!=a2)
	{
		cout<<"0000";
		return 0;
	}
	if(b1[0]!=b2[0]||b1[1]!=b2[1])
	{
		cout<<"1000";
		return 0;
	}
	if(b1[2]=='A'||b1[2]=='B'||b1[2]=='C')
	{
		if(b2[2]!='A'&&b2[2]!='B'&&b2[2]!='C')
		{
			cout<<"1100";
			return 0;
		}
		if(abs(b2[2]-b1[2])!=1)
		{
			cout<<"1110";
			return 0;
		}
	}
	else if(b2[2]!='D'&&b2[2]!='F')
	{
		cout<<"1100";
		return 0;
	}
	cout<<"1111";
	return 0;
}
