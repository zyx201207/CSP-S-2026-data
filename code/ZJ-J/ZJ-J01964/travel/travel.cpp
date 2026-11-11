#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c)cout<<1;
	else cout<<0;
	if(b[0]==d[0]&&b[1]==d[1]&&a==c)cout<<1;
	else cout<<0;
	if(a==c&&b[0]==d[0]&&b[1]==d[1]&&((b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C')||(b[2]>='D'&&b[2]<='E'&&d[2]>='D'&&d[2]<='E')))cout<<1;
	else cout<<0;
	if(a==c&&b[0]==d[0]&&b[1]==d[1]&&((b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C')||(b[2]>='D'&&b[2]<='E'&&d[2]>='D'&&d[2]<='E'))&&abs(b[2]-d[2])==1)cout<<1;
	else cout<<0;
	return 0;
}
