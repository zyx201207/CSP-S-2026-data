#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>b>>c>>d;
	if(a==c)cout<<1;
	else cout<<0;
	if(a==c&&b.substr(0,2)==d.substr(0,2))cout<<1;
	else cout<<0;
	bool flag=((b[2]>='A'&&b[2]<='C')&&(d[2]>='A'&&d[2]<='C'))||((b[2]>='D'&&b[2]<='F')&&(d[2]>='D'&&d[2]<='F'));
	if(a==c&&b.substr(0,2)==d.substr(0,2)&&flag)cout<<1;
	else cout<<0;
	bool flag2=0;
	if(abs(b[2]-d[2])==1)flag2=1;
	else if((b[2]=='D'&&d[2]=='F')||b[2]=='F'&&d[2]=='D')flag2=1;
	if(a==c&&b.substr(0,2)==d.substr(0,2)&&flag&&flag2)cout<<1;
	else cout<<0;
	return 0;
}