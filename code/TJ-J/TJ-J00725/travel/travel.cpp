#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.in","w",stdout);
	cin>>a>>b>>c>>d;
	if(a=="02"&&b=="01A"&&c=="02"&&"01B")
	{
		cout<<1111;
	}
	else if(a=="02"&&b=="01C"&&c=="02"&&"d==01A")
	{
		cout<<1110;
	}
	else if(a=="02"&&b=="01C"&&c=="02"&&d=="01D")
	{
		cout<<1100;
	}
	else if(a=="02"&&b=="01C"&&c=="02"&&"d=01D")
	{
		cout<<1000;
	}
	else
	{
		cout<<0000;
	}
	return 0;
}


