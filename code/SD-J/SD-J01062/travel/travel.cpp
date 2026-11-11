#include<bits/stdc++.h>
#include<cstdio> 
using namespace std;
string c1,s1,c2,s2;
bool x,y,z;
int main() 
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<"1";
		x=1;
	}
	else
	{
		cout<<"0";
	}
	string a=s1.substr(0,2),b=s2.substr(0,2);
	if(a==b&&x)
	{
		cout<<"1";
		y=1;
	}
	else
	{
		cout<<"0";
	}
	if(((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))&&x&&y)
	{
		cout<<"1";
		z=1;
	}
	else
	{
		cout<<"0";
	}
	if(x&&y&&z&&abs(s1[2]-s2[2])==1)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	cout<<endl;
	return 0;
}
