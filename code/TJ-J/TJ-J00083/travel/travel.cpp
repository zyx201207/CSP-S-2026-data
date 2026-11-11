#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopeen("travel.in","r",stdin);
	freopeen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		if(s1==s2)
		{
			if(s1==s2)
			{
				if(s1==s2)
				{
					cout<<"1111"<<endl;
				}
				else
				{
					cout<<"1110"<<endl;
				}
			}
			else
			{
				cout<<"1100"<<endl;
			}
		}
		else
		{
			cout<<"1000"<<endl;
		}
	}
	else
	{
		cout<<"0000"<<endl;
	}
	return 0;
 } 
