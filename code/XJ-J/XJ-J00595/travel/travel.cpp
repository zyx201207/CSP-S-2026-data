#include<bits/stdc++.h>
using namespace std;
//void first(string C_1,string S_1)
//{
//	if(C_1!=S_1)
//	{
//		cout<<"0000";
//	}
//	else
//	{
//		return;
//	}
//	return;
//}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string C_1,C_2,S_1,S_2;
//	int a=1111,b=1110,c=1100,d=1000;
	cin>>C_1>>C_2>>S_1>>S_2;
	if(C_1==S_1)
	{
		if(C_2[0]==S_2[0]&&C_2[1]==S_2[1])
		{
			if((C_2[2]>'C'&&S_2[2]>'C')||(C_2[2]<'D'&&S_2[2]<'D'))
			{
				if(abs(C_2[2]-S_2[2])!=1)
				{
				cout<<"1110";
				}
			else if(abs(C_2[2]-S_2[2])==1)
			{
				cout<<"1111";
			}
		}
		else
		{
			cout<<"1100";
		}
	}
		//	else if(C_2[0]!=S_2[0]&&C_2[1]!=S_2[1])
		//	{
		//		cout<<"1000";
		//	}
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
