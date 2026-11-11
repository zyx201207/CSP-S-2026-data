#include<bits/stdc++.h>
using namespace std;
string n,m,a,b;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m>>a>>b;
	if(n==a&&n!="01"&&n!="16")cout<<1;
	else
	{
		cout<<"0000";
		return 0;
	}
	if(m[0]==b[0]&&m[1]==b[1])
	{
		cout<<1;
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if((m[2]>='D'&&b[2]>='D')||(m[2]<='C'&&b[2]<='C'))
	{
		cout<<1;
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if(abs(m[2]-b[2])==1)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
		return 0;
	}
	return 0;
}
