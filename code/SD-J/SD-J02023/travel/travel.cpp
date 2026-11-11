#include<bits/stdc++.h>
using namespace std;
char a1[5];
char a2[5];
char b2[5];
char b1[5];
char s[5]={'A','B','C','D','F'};
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	
	int ok=1;
	for(int i=0;i<2;i++)
	{
		if(a1[i]!=b1[i])
		{
			ok=0;
		}
	}
	if(ok==0)
	{
		cout<<"0000";
		return 0;
	}
	cout<<1;
	//1
	ok=1;
	for(int i=0;i<2;i++)
	{
		if(a2[i]!=b2[i])
		{
			ok=0;
		}
	}
	if(ok==0)
	{
		cout<<"000";
		return 0;
	}
	cout<<1;
	//2
	int x=0;//ÔÚÍ¬Ò»²à 
	for(int i=0;i<5;i++)
	{
		if(a2[2]==s[i] && i<3)
		{
			x++;
		}
		if(b2[2]==s[i] && i<3)
		{
			x++;
		}
		
	}
	if(x==1)
	{
		cout<<"00";
		return 0;
	}
	cout<<1;
	if(abs(a2[2]-b2[2])>1)
	{
		cout<<0;
	}
	cout<<1;
	return 0;
} 
