#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<bits/stdc++.h>
 int c[4],s[4];
using namespace std;
int main()
{ 
	//freopen("travel.in","r",stdin)
	//freopen("travel.out","w",stdout)
	cin>>c[2]>>s[2];
	if(c[0]==c[1])
	{
		cout<<"1";
	}
	if(c[0][0]==c[0][1]&&c[0][1]==c[1][1])
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}

	if(s[0][2]-'1'==s[1][2]||s[0][2]==s[1][2]-'1')
	{
		cout<<"1";
	}
	else
	{
		cout<<"0 0";
	}
	if(c[2]<='C'&&s[1][2]<='C')||(s[0][2]>'C'&&s[1][2]>'C')
	{
		cout<<"1";
	}
	else
	{
		cout<<"0 0 0";
	}
	//fclose(stdin)
	//fclose(stdout)
	return 0;
}
