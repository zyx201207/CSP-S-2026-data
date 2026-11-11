#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cx,sx,cr,sr;
	cin>>cx>>sx>>cr>>sr;
	if(cx==cr&&cx!="01"&&cr!="01")
	{
		cout<<1;
		
	}
	else
	{
		cout<<0;
	}
	if(sx[0]==sr[0]&&sx[1]==sx[1])
	{
		cout<<1;
			
	}
	else
	{
		cout<<0;
	}
	if((sx[0]==sr[0]&&sx[1]==sx[1])&&((sx[2]>='A'&&sx[2]<='C'&&sr[2]>='A'&&sr[2]<='C')||(sx[2]>='D'&&sx[2]<='F'&&sr[2]>='D'&&sr[2]<='F')))
	{
		cout<<1;
				
	}
	else
	{
		cout<<0;
	}
	if(sx[2]+1==sr[2]||sx[2]-1==sr[2])
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
} 
/*
02 01C 02 01A
*/
