#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,num1="",num2="";
	char seat1,seat2;
	int i;
	cin>>c1>>s1>>c2>>s2;
	for(i=0;i<2;i++)
	{
		num1+=s1[i];
		num2+=s2[i];
	}
	seat1=s1[2];
	seat2=s2[2];
	if(c1==c2)
	{
		cout<<"1";
		if(num1==num2)
		{
			cout<<"1";
			if((seat1>='A'&&seat1<='C'&&seat2>='A'&&seat2<='C'))
			{
				cout<<"1";
				if((seat1=='A'&&seat2=='B')||(seat1=='B'&&seat2=='A'))
				{
					cout<<"1";
				}
				else if((seat1=='B'&&seat2=='C')||(seat1=='C'&&seat2=='B'))
				{
					cout<<"1";
				}
				else
				{
					cout<<"0";
				}
			}
			else if((seat1=='D'&&seat2=='F')||(seat1=='F'&&seat2=='D'))
			{
				cout<<"11";
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
