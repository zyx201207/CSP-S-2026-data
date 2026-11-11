#include<bits/stdc++.h>
using namespace std;

int main()
{
 	freopen("travel.in","r",stdin);
 	freopen("travel.out"£¬"w",stdout);
 	string r1,x1,r2,x2;
 	cin>>r1>>r2>>x1>>x2;
 	if(r1==x1)
 	{
 		cout<<"1";
 		if(r2[0]==x2[0]&&r2[1]==x2[1])
 		{
 			cout<<"1";
 			if(abs(int(r2[2]-'A')-int(x2[2]-'A'))<=2&&((int(r2[2]-'A')<=2&&int(x2[2]-'A')<=2)||(int(r2[2]-'A')>=3&&int(x2[2]-'A')>=3)))
 			{
	 			cout<<1;
	 			if(abs(int(r2[2]-'A')-int(x2[2]-'A'))==1)
	 			{
	 				cout<<"1";
				}
				else
				{
					cout<<"0";	
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
	else
	{
		cout<<"0000";
	}
	return 0;
}
