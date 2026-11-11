#include<bits/stdc++.h>
using namespace std;
int pan(string a1)
{
	if(a1[2]>='A'&&a1[2]<='C')
	{
		return 1;
	}
	else
	{
		return 2;
	}
}
bool ce(string a,string b)
{
	if((a[2]=='C'&&b[2]=='D')||(a[2]=='D'&&b[2]=='C'))
	{
		cout<<1<<endl; 
		return false;
	}
	if((a[2]-1==(b[2]-1+1))||(a[2]+1==(b[2]-1+1)))
	{
		
		return 1;
	}
	else
	{
		
		return false;
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string che1,zuo1,che2,zuo2;
	cin>>che1>>zuo1>>che2>>zuo2;
	if(che1==che2)
	{
		int pai1,pai2;
		pai1=(zuo1[0]-'0')*10+zuo1[1]-'0';
		pai2=(zuo2[0]-'0')*10+zuo2[1]-'0';
		if(pai1==pai2)
		{
			int w1,w2;
			w1=pan(zuo1);
			w2=pan(zuo2);
			if(w1==w2)
			{
				if(ce(zuo1,zuo2))
				{
					cout<<"1111";
				}
				else
				{
					cout<<"1110";
				}
			}
			else
			{
				cout<<"1100";
			}
		}
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
