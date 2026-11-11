#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	int aa,cc,bs,ds;
	cin>>a>>b>>c>>d;
	aa=(a[0]-'0')*10+(a[1]-'0');
	cc=(c[0]-'0')*10+(c[1]-'0');
	if(aa==cc)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	int bb=b.length();
	int dd=d.length();
	int q=b[bb-1]-'A',w=d[dd-1]-'A';
	bs=(b[0]-'0')*10+(b[1]-'0');
	ds=(d[0]-'0')*10+(d[1]-'0');
	if(bs==ds)
	{
		cout<<"1";
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if((q==2&&w==3)||(q==3&&q==2))
	{
		cout<<"00";
		return 0;
	}
	else
	{
		cout<<"1";
	}
	if(abs(q-w)==1)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	cout<<"Kk";
	return 0;
}