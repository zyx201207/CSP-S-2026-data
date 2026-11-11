#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
int a[4];
int main()
{
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3)
		a[0]=1;
	else
		a[0]=0;
		
	//000000000000000000	
	int f=1;
	for(int i=0;i<2;i++)
	{
		if(c2[i]!=c4[i])
		{
			a[1]=0;
			f=0;
		}
		
	}
	if(f)
		a[1]=1;
	//00000000000000000000	
		
	if((c2[2]=='C'||c2[2]=='B'||c2[2]=='A'))
	{
		if(c4[2]=='C'||c4[2]=='B'||c4[2]=='A')
			a[2]=1;
		else
			a[2]=0;
	}
	if(c2[2]=='D'||c2[2]=='F')
	{
		if(c4[2]=='D'||c4[2]=='F')
		{
			a[2]=1;
		}
		else
		{
			a[2]=0;
		}
	}
	//000000000000000
	if(a[2]==0)
	{
		a[3]=0;	
	}
	else
	{
		if(abs(c2[2]-c4[2])==1)
		{
			a[3]=1;	
		}
		else
		{
			a[3]=0;
		}
	}
	for(int i=0;i<4;i++)
	{
		cout<<a[i];
	}
	return 0;
 } 
