#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int p =0;
	if(a==c)
	{
		p=1;
		cout << 1;
	}
	else
		cout << 0;
	string b1,d1;
	b1+=b[0];
	b1+=b[1];
	d1+=d[0];
	d1+=d[1];
	char b2,d2;
	b2=b[2];
	d2=d[2];
	int u = 0;
	if(b1==d1&&p==1)
	{
		cout << 1;
		u=1;
	}else
		cout << 0;
	int o =0;
	if(u==1)
	{
		if('A'<=b2&&b2<='C'&&'A'<=d2&&d2<='C')
		{
			o=1;
			cout << 1;
		}
		else if('D'<=b2&&b2<='F'&&'D'<=d2&&d2<='F')
		{
			o=1;
			cout << 1;
		}
		else
			cout << 0;
	}else
		cout << 0;
	if(o==1)
	{
		if(b2+1==d2||b2-1==d2)
			cout << 1;
		else
			cout << 0;
	}else
		cout << 0;
	return 0;
}
