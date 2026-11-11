#include<bits/stdc++.h>
using namespace std;
char a,b,x,y;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	a=c1[0];b=c1[1];
	x=c2[0];y=c2[1];

      if(a==x&&b==y)
	{
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			
			if(s1[2]>=65&&s1[2]<=67&&s2[2]>=65&&s2[2]<=67)
			{
				if(s1[2]-s2[2]==-1||s1[2]-s2[2]==1)
				{
					cout<<1111;
					return 0;
				}
				else
				{
					cout<<1110;
					return 0;
				}
				
			}
			else if(s1[2]>=68&&s1[2]<=69&&s2[2]>=68&&s2[2]<=69)
			{
				cout<<1111;
				return 0;
			}
			else
			{
				cout<<1100;
				return 0;
			}
			
		}
		else
		{
			cout<<1000;
			return 0;
		}
	}	
	else
	{
		cout<<"0000";
		return 0;
	}
		
	
	
	
	return 0;
}
