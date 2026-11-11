//孙国轩 SN-J00764 西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","w",stdin);
	freopen("travel.out","r",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	bool flag=false;
	if(a==c)
	{
		cout<<1;
		flag=true;
	}
	if(flag)
	{
		if(b[0]==d[0]&&b[1]==d[1])
		{
			cout<<1;
		}
		else
		{
			cout<<0<<0<<0;
			return 0;
		}
		if((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='D'||d[2]=='F'))
		{
			cout<<0<<0;
			return 0;
		}
		else
		{
			cout<<1;
		}
		if((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&d[2]=='C')||(b[2]=='D'&&d[2]=='F')||(b[2]=='B'&&d[2]=='A')||(b[2]=='C'&&d[2]=='B')||(b[2]=='F'&&d[2]=='D')
		)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	else
	{
		cout<<0<<0<<0<<0;
	}
}
