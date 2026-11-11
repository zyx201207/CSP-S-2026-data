#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
char c2,d2;
long long c1,d1,ans;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>c>>b>>d;
	c1=(c[0]-'0')*10+(c[1]-'0');
	d1=(d[0]-'0')*10+(d[1]-'0');
	if(a==b)
	{
		cout<<1;
		ans++;
	}
	else
	{
		cout<<0;
	}
	if(c1==d1&&ans==1)
	{
		cout<<1;
		ans++;
	}
	else
	{
		cout<<0;
	}
	c2=c[2];
	d2=d[2];
	if(((c2>='A'&&c2<='C'&&d2>='A'&&d2<='C')||(c2>='D'&&c2<='F'&&d2>='D'&&d2<='F'))&&ans==2)
	{
		cout<<1;
		ans++;
	}
	else
	{
		cout<<0;
	}
	if((c2>='A'&&c2<='C'&&d2>='A'&&d2<='C')&&ans==3)
	{
		if(c2+1==d2||d2+1==c2)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	else if(c2>='D'&&c2<='F'&&d2>='D'&&d2<='F')
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
