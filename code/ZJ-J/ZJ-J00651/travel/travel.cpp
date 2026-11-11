#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	if(x1==x2)
	{
		cout<<'1';
		if(y1[0]==y2[0]&&y1[1]==y2[1])
		{
			cout<<'1';
			if(int(y1[2]-'A')<=2&&int(y2[2]-'A')<=2||int(y1[2]-'A')>2&&int(y2[2]-'A')>2)
			{
				cout<<'1'; 
				if(abs(int(y1[2]-'A')-int(y2[2]-'A'))==1)
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
	else
	{
		cout<<"0000";
	}
	return 0;
} 
