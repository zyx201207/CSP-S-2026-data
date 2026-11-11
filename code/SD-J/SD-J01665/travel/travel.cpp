#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
bool ss1,ss2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(s1[2]=='D'||s1[2]=='F') ss1=0;
	else ss1=1;
	if(s2[2]=='D'||s2[2]=='F') ss2=0;
	else ss2=1;
	if(c1==c2)
		cout<<"1";
	else
	{
		cout<<"0000";
		return 0;
	}
	if(s1.substr(0,2)==s2.substr(0,2))
		cout<<1;
	else
	{
		cout<<"000";
		return 0;
	}
	if(ss1==ss2)
		cout<<"1";
	else
	{
		cout<<"00";
		return 0;
	}
	int a=int(s1[2]),b=int(s2[2]);
	if(abs(a-b)==1)
		cout<<"1";
	else
		cout<<"0";
	return 0;
}
