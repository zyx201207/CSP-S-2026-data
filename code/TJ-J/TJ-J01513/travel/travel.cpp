#include<bits/stdc++.h> 
using namespace std;
string a,b,c,d;
bool ok=1;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
		ok=0;
	}
	if(b[0]==d[0]&&b[1]==d[1]&&ok)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
		ok=0;
	}
	int x=(b[2]-'A'),y=(d[2]-'A');
	if(x<=2&&y<=2&&ok)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
		ok=0;
	}
	if(abs(x-y)==1&&ok)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
		ok=0;
	}
	return 0;
}
