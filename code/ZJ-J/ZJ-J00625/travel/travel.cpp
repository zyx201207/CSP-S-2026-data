#include<bits/stdc++.h>
using namespace std;
struct place
{
	int c,p;
	char w;
}r,x;
istream& operator>>(istream& in,place& p)
{
	string str;
	in>>p.c;
	in>>str;
	p.p=(str[0]-'0')*10+(str[1]-'0');
	p.w=str[2];
	return in;
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r>>x;
	bool a,b,c,d;
	if(r.c==x.c)
		a=1;
	else
		a=0;
	if(r.p==x.p)
		b=1;
	else
		b=0;
	if((('A'<=r.w&&r.w<='C')&&('A'<=x.w&&x.w<='C'))||(('D'<=r.w&&r.w<='E')&&('D'<=x.w&&x.w<='E')))
		c=1;
	else
		c=0;
	if(a&&b&&c&&abs(r.w-x.w)==1)
		d=1;
	else
		d=0;
	cout<<a<<b<<c<<d;
	return 0;
}
