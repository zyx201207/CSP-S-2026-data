#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	bool flag=true;
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
		cout<<"1";
	else
	{
		cout<<"0";
		flag=false;
	}
	if(s2[0]==s1[0]&&s2[1]==s1[1]&&flag)
		cout<<"1";
	else
	{
		cout<<"0";
		flag=false;
	}
	if(((s1[2]<'D'&&s2[2]<'D')||(s1[2]>='D'&&s2[2]>='D'))&&flag)
		cout<<"1";
	else
	{
		cout<<"0";
		flag=false;
	}
	if(!flag)
	{
		cout<<"0";
		return 0;
	}
	if(abs(s1[2]-s2[2])==1)
		cout<<"1";
	else
		cout<<"0";
	return 0;
}
