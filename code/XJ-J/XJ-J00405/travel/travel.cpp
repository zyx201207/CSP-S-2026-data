#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int b3,d3;
	bool f = true;
	if(b[2]=='A'||b[2]=='B'||b[2]=='C') b3 = 1;
	else b[3] = 2;
	if(d[2]=='A'||d[2]=='B'||d[2]=='C') d3 = 1;
	else d[3] = 2;
	
	if(a==c) cout<<1;
	else
	{
		cout<<0;
		f = false;
	}
	
	if(b[0]==d[0]&&b[1]==d[1]&&f==true) cout<<1;
	else
	{
		cout<<0;
		f = false;
	}
	
	if(b[0]==d[0]&&b[1]==d[1]&&b3==d3&&f==true) cout<<1;
	else
	{
		cout<<0;
		f = false;
	}
	
	if(b[0]==d[0]&&b[1]==d[1]&&b3==d3&&f==true)
	{
		if(abs(b[2]-d[2])==1&&max(b[2],d[2])!='D'&&f==true) cout<<1;
		else cout<<0;
	}
	else
	{
		cout<<0;
		f = false;
	}
	
	return 0;
}
