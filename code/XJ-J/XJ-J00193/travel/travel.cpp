#include <bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int a1=(a[0]-'0')*10+(a[1]-'0'),b1=(b[0]-'0')*10+(b[1]-'0'),c1=(c[0]-'0')*10+(c[1]-'0'),d1=(d[0]-'0')*10+(d[1]-'0');
	char x=b[2],y=d[2];
	if (a1==c1)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if (a1==c1&&b1==d1)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if (a1==c1&&b1==d1&&((x>='D'&&y>='D')||(x<='C'&&y<='C')))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if (a1==c1&&b1==d1&&((x>='D'&&y>='D')||(x<='C'&&y<='C')))
	{
		if ((x=='A'&&y=='B')||(x=='B'&&y=='A')||(x=='B'&&y=='C')||(x=='C'&&y=='B')||(x=='D'&&y=='F')||(x=='F'&&y=='D'))
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
		cout<<0;
	}
	return 0;
}
