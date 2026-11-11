#include<bits/stdc++.h>
using namespace std;
string x,y,a,b;
int e,f,i;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>a>>y>>b;
	if(x==y)
	cout<<"1";
	else
	{
		cout<<"0"<<"0"<<"0"<<"0";
		return 0;
	}
		e=a[2]-'0';
		f=b[2]-'0';	
	if(a[0]==b[0]&&a[1]==b[1])
	{
		cout<<"1";
		if(a[2]>='A'&&a[2]<='C'&&b[2]>='A'&&b[2]<='C'||a[2]>='D'&&a[2]<='F'&&b[2]>='D'&&b[2]<='F')
		{
			cout<<"1";	
			if(e+1==f||e-1==f)
			cout<<"1";
			else
			cout<<"0";
			}
		else
			cout<<"0"<<"0";
	}
	else
	cout<<"0"<<"0"<<"0";
	return 0;
}