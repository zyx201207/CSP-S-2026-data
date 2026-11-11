#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	int i,l=0,p=0;
	cin>>a>>b>>c>>d;
	if(a==c) cout<<1;
	else cout<<0;
	if(b[0]==d[0]&&b[1]==d[1]&&b[2]!=d[2]) cout<<1;
	else cout<<0,p=1;
	if(abs(b[2]-d[2])==1&&b[2]<'D'&&d[2]<'D'&&!p||abs(b[2]-d[2])==2&&!p) cout<<1;
	else cout<<0,l=1;
	if(!l&&abs(b[2]-d[2])==1) cout<<1;
	else cout<<0;
	return 0;
}
