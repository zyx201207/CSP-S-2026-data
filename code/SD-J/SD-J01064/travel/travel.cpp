#include<iostream>
#include<stdio.h>
#include<string>
#include<cmath>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<'1';
		string ss="",sss="";
		ss+=s1[0]+s1[1];
		sss+=s2[0]+s2[1];
		if(ss==sss)
		{
			cout<<'1';
			if((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='E'&&s2[2]>='D'&&s2[2]<='E'))
			{
				cout<<'1';
				if(abs(int(s1[2]-s2[2]))<=1)
				{
					cout<<'1'<<endl;
				}
				else
				{
					cout<<'0'<<endl;
				}
			}
			else
			{
				cout<<"00"<<endl;
			}
		}
		else
		{
			cout<<"000"<<endl;
		}
	}
	else
	{
		cout<<"0000"<<endl;
	}
	return 0;
} 
