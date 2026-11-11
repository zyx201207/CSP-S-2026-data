#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
string xr,xx,wr,wx,l="qABCDF";
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>xr>>wr>>xx>>wx;
	if(xr==xx) 
	{
		cout<<"1";
		if((wr[0]==wx[0])&&(wr[1]==wx[1])) 
		{
			cout<<"1";
			if(((wr[2]==l[4])&&(wx[2]==l[5]))||((wr[2]==l[5])&&(wx[2]==l[4]))) cout<<"11";
			else if(((wr[2]==l[1])&&(wx[2]==l[2]))||((wr[2]==l[2])&&(wx[2]==l[1]))||((wr[2]==l[2])&&(wx[2]==l[3]))||((wr[2]==l[3])&&(wx[2]==l[2]))) cout<<"11";
			else if(((wr[2]==l[1])&&(wx[2]==l[3]))||((wr[2]==l[3])&&(wx[2]==l[1]))) cout<<"10";
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}