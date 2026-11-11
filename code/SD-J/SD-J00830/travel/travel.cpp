#include<bits/stdc++.h>
using namespace std;
char a[2],a1[3],b[2],b1[3];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a[0]>>a[1];
	cin>>a1[0]>>a1[1]>>a1[2];
	cin>>b[0]>>b[1];
	cin>>b1[0]>>b1[1]>>b1[2];
	if(a[0]==b[0]&&a[1]==b[1])
	{
		cout<<"1";
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if(a1[0]==b1[0]&&a1[1]==b1[1])
	{
		cout<<"1";
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if((a1[2]=='A'&&(b1[2]=='B'||b1[2]=='C'))||(a1[2]=='B'&&(b1[2]=='A'||b1[2]=='C'))||(a1[2]=='C'&&(b1[2]=='B'||b1[2]=='A')))
	{
		cout<<"1";
	}
	else if((a1[2]=='D'&&b1[2]=='F')||(a1[2]=='F'&&b1[2]=='D'))
	{
		cout<<"1";
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if((a1[2]=='A'&&b1[2]=='B')||(a1[2]=='B'&&b1[2]=='C')||(b1[2]=='A'&&a1[2]=='B')||(a1[2]=='C'&&b1[2]=='B'))
	{
		cout<<"1";
		return 0;
	}
	else if((a1[2]=='D'&&b1[2]=='F')||(a1[2]=='F'&&b1[2]=='D'))
	{
		cout<<"1";
		return 0;
	}
	cout<<"0";
	return 0;
}
