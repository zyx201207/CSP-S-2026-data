#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c3;
	string c2,c4;
	cin>>c1>>c2>>c3>>c4; 
	string c5,c6,c7,c8,c2c,c4c;
	if(c1==c3)
	{
		c2c=c2;
		c4c=c4;
		c5=c2.erase(2,1);
		c6=c4.erase(2,1);
		if(c5==c6)
		{
			c7=c2c.erase(0,2);
			c8=c4c.erase(0,2);
			if(c7=="D" && c8=="F")
			{
				cout<<"1111";
			}
			else if(c7=="F" && c8=="D")
			{
				cout<<"1111";
			}
			else if(c7=="A" && c8=="B")
			{
				cout<<"1111";
			}
			else if(c7=="B" && c8=="A")
			{
				cout<<"1111";
			}
			else if(c7=="B" && c8=="C")
			{
				cout<<"1111";
			}
			else if(c7=="C" && c8=="B")
			{
				cout<<"1111";
			}
			else if(c7=="C" && c8=="A")
			{
				cout<<"1110";
			}
			else if(c7=="A" && c8=="C")
			{
				cout<<"1110";
			}
			else
			{
				cout<<"1100";
			}
		}
		else
		{
			cout<<"1000";
		}
	}
	else
	{
		cout<<"0000";
	}
	return 0;
 } 
