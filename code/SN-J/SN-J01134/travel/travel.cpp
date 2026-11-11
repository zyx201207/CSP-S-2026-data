#include<bits./stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	bool e=1;
	if(a==c)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
		e=0;
	}
	if(e==1&&b[0]==d[0]&&b[1]==d[1])
	{
		cout<<1;
	}
	else
	{
		e=0;
		cout<<0;
	}
	if(e==1&&(b[2]<='C'&&d[2]<='C')||(b[2]>='D'&&d[2]>='D'))
	{
		cout<<1;
	}
	else
	{
		e=0;
		cout<<0;
	}
	if(e==1&&((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&d[2]=='C')||(b[2]=='B'&&d[2]=='A')||(b[2]=='C'&&d[2]=='B')||(b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D')))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
 } 
