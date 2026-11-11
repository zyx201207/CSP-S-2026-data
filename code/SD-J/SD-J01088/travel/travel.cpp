#include<bits/stdc++.h>
using namespace std;
string che1,che2,zuo1,zuo2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>che1>>zuo1>>che2>>zuo2;
	
	if(che1==che2)
	{
		cout<<"1";
		//cout<<zuo1[0]<<zuo2[0]<<zuo1[1]<<zuo2[1];
		if(zuo1[1]==zuo2[1]&&zuo1[0]==zuo2[0])
		{
			cout<<"1";
			char a=char(zuo1[2]);
			char b=char(zuo2[2]);
			
			if((a>='A'&&a<='C'&&b>='A'&&b<='C')||(a>='D'&&a<='E'&&b>='D'&&b<='E'))
			{
				//cout<<a<<" "<<b; 
				cout<<1;
				if(abs(int(a-b))==1)
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
