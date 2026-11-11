#include<bits/stdc++.h>
using namespace std;
char a[100],b[100];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=5;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=5;i++)
	{
		cin>>b[i];
	}
//	-------------------
	bool q=1;
	for(int i=1;i<=2;i++)
	{
		if(a[i]!=b[i])
		{
			q=0;
		}
	}
	if(q==0)
	{
		cout<<"0000";
		return 0;
	}
//	----------------
	bool w=1;
	for(int i=3;i<=4;i++)
	{
		if(a[i]!=b[i])
		{
			w=0;
		}
	}
	if(w==0)
	{
		cout<<"1000";
		return 0;
	}
//	---------------------------
	bool e=1;
	if(!(a[5]=='D'||a[5]=='F')&&(b[5]=='D'||b[5]=='F'))
	{
		e=0;
	}
	if(!(a[5]=='A'||a[5]=='B'||a[5]=='C')&&(b[5]=='A'||b[5]=='B'||b[5]=='C'))
	{
		e=0;
	}
	if(e==0)
	{
		cout<<"1100";
		return 0;
	}
//	-------------------------------
	bool r=1;
	if(a[5]=='A'&&b[5]=='C')
	{
		r=0;
	}
	if(b[5]=='A'&&a[5]=='C')
	{
		r=0;
	}
	if(r==0)
	{
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
} 
