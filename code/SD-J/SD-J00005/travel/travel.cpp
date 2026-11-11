#include<iostream>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string co,so,ct,st;
	cin>>co>>so>>ct>>st;
	if(co==ct)
	{
		cout<<1;
		if(so[0]==st[0]&&so[1]==st[1])
		{
			cout<<1;
			if((so[2]>='D'&&st[2]>='D')||(so[2]<='C'&&st[2]<='C'))
			{
				cout<<1;
				char c11=so[2],c22=st[2];
				if(c11>c22)//swap(c11,c22) 
				{
					char t=c11;
					c11=c22;
					c22=t;
				}
				if(c22==c11+1)
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
