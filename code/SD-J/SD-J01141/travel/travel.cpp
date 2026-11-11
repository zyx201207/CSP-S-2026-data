#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<cmath>
using namespace std;
char x1,x2,xr,xx;
int rc,xc,rz,xz,r1,x3;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x1>>x2;
	rc=(x1-'0')*10+(x2-'0');
	cin>>x1>>x2>>xr;
	rz=(x1-'0')*10+(x2-'0');
	cin>>x1>>x2;
	xc=(x1-'0')*10+(x2-'0');
	cin>>x1>>x2>>xx;
	xz=(x1-'0')*10+(x2-'0');
	if(rc==xc)
	{
		cout<<'1';
	}	
	else
	{
		cout<<"0000"<<endl;
		return 0;
	}
	if(rz==xz)
	{
		cout<<'1';
	}
	else
	{
		cout<<"000"<<endl;
		return 0;
	}
	r1=xr-'A'+1,x3=xx-'A'+1;
	if(r1==4)
	{
		r1++;
	}
	if(x3==4)
	{
		x3++;
	}
	if(((r1==1||r1==2||r1==3)&&(x3==1||x3==2||x3==3))||((r1==5||r1==6)&&(x3==5)||x3==6))
	{
		cout<<'1';
	}
	else
	{
		cout<<"00"<<endl;
		return 0;
	}
	if(abs(x3-r1)==1)
	{
		cout<<'1';
	}
	else
	{
		cout<<'0';
	}
	cout<<endl;
	return 0;
}
