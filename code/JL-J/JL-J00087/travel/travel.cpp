#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c)
	cout<<"1";
	if(a!=c)
	{
	 cout<<"0000";
	 return 0;
}
	if(b[1]==d[1]&&b[0]==d[0])
	cout<<"1";
	if(b[1]!=d[1]||b[0]!=d[0])
	{
	 cout<<"000";
	 return 0;
}
	if(b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C')
	cout<<"1";
if(b[2]>='A'&&b[2]<='C'&&d[2]>='D'&&d[2]<='F')
	{
		cout<<"00";
		return 0;
	}
	if(b[2]>='D'&&b[2]<='F'&&d[2]>='A'&&d[2]<='C')
	{
		cout<<"00";
		return 0;
	}
	if(b[2]>='D'&&b[2]<='F'&&d[2]>='D'&&d[2]<='F')
	cout<<"1";
if(b[2]>='D'&&b[2]<='F'&&d[2]>='A'&&d[2]<='C')
	{
		cout<<"00";
		return 0;
	}
	if(b[2]>='A'&&b[2]<='C'&&d[2]>='D'&&d[2]<='F')
	{
		cout<<"00";
		return 0;
	}
	if(b[2]=='D'&&d[2]=='F')
	cout<<"1";
	if(b[2]=='F'&&d[2]=='D')
	cout<<"1";
	if(b[2]=='A'&&d[2]=='B')
	cout<<"1";
	if(b[2]=='B'&&d[2]=='C')
	cout<<"1";
	if(b[2]=='B'&&d[2]=='A')
	cout<<"1";
	if(b[2]=='B'&&d[2]=='C')
	cout<<"1";
	
if(b[2]=='A'&&d[2]=='C')
{
	 cout<<"0";
	return 0;
}	
		if(b[2]=='C'&&d[2]=='A')
	{
	 cout<<"0";
	return 0;
}
if(b[2]=='A'&&d[2]=='D')
	{
	cout<<"0";
	return 0;
}
if(b[2]=='D'&&d[2]=='A')
	{
	cout<<"0";
	return 0;
}
	if(b[2]=='A'&&d[2]=='F')
	{
	 cout<<"0";
	return 0;
}
	if(b[2]=='F'&&d[2]=='A')
	{
	 cout<<"0";
	return 0;
}
if(b[2]=='B'&&d[2]=='D')
	{
	 cout<<"0";
	return 0;
}
if(b[2]=='D'&&d[2]=='B')
	{
	 cout<<"0";
	return 0;
}
	if(b[2]=='B'&&d[2]=='F')
	{
	 cout<<"0";
	return 0;
}
	if(b[2]=='F'&&d[2]=='B')
	{
	 cout<<"0";
	return 0;
}
if(b[2]=='C'&&d[2]=='D')
	{
	 cout<<"0";
	return 0;
}
if(b[2]=='D'&&d[2]=='C')
	{
	 cout<<"0";
	return 0;
}
	if(b[2]=='C'&&d[2]=='F')
	{
	 cout<<"0";
	return 0;
}
	if(b[2]=='F'&&d[2]=='C')
	{
	 cout<<"0";
	return 0;
}


	return 0;
}
