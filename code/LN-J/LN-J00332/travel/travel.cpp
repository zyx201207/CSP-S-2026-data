#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;

	if(c1==c2)
	{
		cout<<'1';
		int a1=(s1[1]-'0')+(s1[0]-'0')*10;
		int b1=(s2[1]-'0')+(s2[0]-'0')*10;
		int a=s1[2]-'A';
		int b=s2[2]-'A';

		if(a1==b1)
		{
			cout<<1;
			if(a>=3 and b>=3)
			{
				cout<<"11";
			
				
			}
			if(a<3 and b<3)
			{
				cout<<'1';
				if(a-b!=2 and b-a!=2)
				{
					cout<<'1';
					}
					else
					{
						cout<<'0';
						}
			}
			else
			{
				cout<<"00";
				}
		}
		else
		{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
