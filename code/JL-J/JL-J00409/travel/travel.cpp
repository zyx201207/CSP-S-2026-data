#include<bits/stdc++.h>
using namespace std;
bool x=0,y=0;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a!=c)
	{
		cout<<"0000";
		return 0;
	}
	if(a==c)
	{
		x=1;
		cout<<'1';
		
	}
	else
	{
		cout<<'0';
	}
	if(b[0]==d[0]&&b[1]==d[1])
	{
		y=1;
		cout<<'1';
		
	}
	else
	{
		cout<<'0';
	}
	if(((b[2]=='A'&&d[2]=='B')||(b[2]=='A'&&d[2]=='C')||(b[2]=='A'&&d[2]=='A')||(b[2]=='B'&&d[2]=='C')||(b[2]=='B'&&d[2]=='A')||(b[2]=='B'&&d[2]=='B')||(b[2]=='C'&&d[2]=='A')||(b[2]=='C'&&d[2]=='B')||(b[2]=='C'&&d[2]=='C')
	||(b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D'))&&x&&y)
	{
		cout<<'1';
	}
	else
	{
		cout<<'0';
	}
	if(((abs((b[1]-'0')-(d[1]-'0'))==1&&b[2]==d[2])||((b[0]==d[0])&&(b[1]==d[1])&&(abs((b[2]-'0')-(d[2]-'0'))==1)))&&
		!(b[2]=='C'&&d[2]=='D')&&!(b[2]=='D'&&d[2]=='C'))
	{
		 cout<<'1';
	}
	else
	{
		cout<<'0';
	}
	return  0;
}
