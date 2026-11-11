#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string n;
	getline(cin,n);
	int a,b,c,d;
	a=(int(n[0])-48)*10;
	b=int(n[1])-48;
	c=(int(n[7])-48)*10;
	d=int(n[8])-48;
	if(a+b==c+d)cout<<1;
	else
	{
		cout<<"0000";
		return 0;
	}
	
	a=(int(n[3])-48)*10;
	b=int(n[4])-48;
	c=(int(n[10])-48)*10;
	d=int(n[11])-48;
	if(a+b==c+d)cout<<1;
	else
	{
		cout<<"000";
		return 0;
	}
	
	
	if((n[5]=='A'||n[5]=='B'||n[5]=='C')&&(n[12]=='A'||n[12]=='B'||n[12]=='C'))
	{
		cout<<1;
		if(abs(int(n[5])-int(n[12]))==1)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	else if((n[5]=='D'||n[5]=='F')&&(n[12]=='D'||n[12]=='F'))
	{
		cout<<11;
	}
	else
	{
		cout<<"00";
	}
	
	
} 
