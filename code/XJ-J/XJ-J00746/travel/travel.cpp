#include <iostream>
using namespace std;
int c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
		if((s2[1]==s1[1])&&(s2[0]==s1[0]))
		{
			cout<<1;
			if(s1[2]=="A"||"B"||"C")
			{
				if(s2[2]=="A"||"B"||"C")
				{
					cout<<1;
				}
				else
				{
					cout<<0;
				}
			}
			if(s2[2]=="F"||"D")
			{
				if(s1[2]=="f"||"D")
				{
					cout<<1;
				}
				else
				{
					cout<<0;
				}
			}
		}
		else
		{
			cout<<0;
		}
	}
	else
	{
		cout<<0;
	}
	cout<<0;
}