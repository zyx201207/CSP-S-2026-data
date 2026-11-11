#include<iostream>
#include<cstdio>
using namespace std;
string c1,c2,s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
	{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0] && s1[1]==s2[1])
	{
		int a=int(s1[2]),b=int(s2[2]);
		if(s1[2]=='F' && s2[2]=='D' || s2[2]=='F' && s1[2]=='D')
		{
			cout<<"1111";
			return 0;
		}
		else if(s1[2]=='C' && s2[2]=='D' || s2[2]=='C' && s1[2]=='D')
		{
			cout<<"1100";
			return 0;
		}
		else if(a+1==b || b+1==a)
		{
			cout<<"1111";
			return 0;
		}
		else if(s1[2]=='A' && s2[2]=='C' || s2[2]=='A' && s1[2]=='C')
		{
			cout<<"1110";
			return 0;
		}
		else cout<<"1110";
	}
	else cout<<"1000";
	return 0;
}
