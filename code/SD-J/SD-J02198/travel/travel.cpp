#include<iostream>
using namespace std;
string c1,c2,c3,c4;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4; 
	if(c1==c3)
	{
		cout<<1;
		
		if(c2[1]+c2[0]==c4[1]+c4[0])
		{
			cout<<1;
			if((c2[2]=='D'&&c4[2]=='F')||(c2[2]<='C'&&c4[2]<='C'))
			{
				cout<<1;
				if(max(c2[2]-'0',c4[2]-'0')-min(c2[2]-'0',c4[2]-'0')==1)
				{
					cout<<1;
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
