#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	bool t = true;
	if(a == c)
	{
		cout<<1;
	}
	else
	{
		t = false;
		cout<<0;
	}
	if(t && b[0] == d[0] && b[1] == d[1])
	{
		cout<<1;
	}
	else
	{
		t = false;
		cout<<0;
	}
	if(t && (((b[2] == 'A' || b[2] == 'B' || b[2] == 'C') && (d[2] == 'A' || d[2] == 'B' || d[2] == 'C')) || ((b[2] == 'D' || b[2] == 'E') && (c[2] == 'D' || c[2] == 'E'))))
	{
		cout<<1;
	}
	else
	{
		t = false;
		cout<<0;
	}
	if(t && ((int)b[2]-(int)d[2] == 1 || (int)b[2]-(int)d[2] == -1))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
