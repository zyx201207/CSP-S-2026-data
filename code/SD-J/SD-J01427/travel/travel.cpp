#include<iostream>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<"1";
	}
	if(s1[1]==s2[1])
	{
		cout<<"1";
		
	}
	if(s1[1]!=s2[1])
	{
		cout<<"000";
		return 0;
	}
	if((s1[2]<39&&s2[2]<39) || (s1[2]>=39&&s2[2]>=39))
	{
		cout<<"1";
		
	}
	else
	{
		cout<<"0";
	}
	if(s1[1]==s2[1]&&s1[2]-s2[2]<=1&&s1[2]-s2[2]>-2)
	{
		if((s1[2]!=38&&s2[2]!=39)||(s1[2]!=39&&s2[2]!=38))
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	
	
	
	
	
	
	return 0;
	
 } 
