#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<2;i++)
	{
		if(c1[i]!=c2[i])
		{
			cout<<"0000";
			return 0;
		}
	}
	cout<<"1";
	for(int i=0;i<2;i++)
	{
		if(s1[i]!=s2[i])
		{
			cout<<"000";
			return 0;
		}
	}
	cout<<"1";
	if(s1[2]=='A' || s1[2]=='B' || s1[2]=='C')
	{
		if(s2[2]=='D' || s2[2]=='F')
		{
			cout<<"00";
			return 0;
		}
		else cout<<"1";
	}
	else if(s1[2]=='D' || s1[2]=='F')
	{
		if(s2[2]=='A' || s2[2]=='B' || s2[2]=='C')
		{
			cout<<"00";
			return 0;
		}
		else cout<<"1";
	}
	if(abs((s1[2]-'0')-(s2[2]-'0'))!=1)
	{
		cout<<"0";
		return 0;
	}
	cout<<"1";
	return 0;
}
