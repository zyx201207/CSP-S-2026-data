#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(b[2]=='F') b[2]='E';
	if(d[2]=='F') d[2]='E';
	if(a==c) cout<<1;
	else cout<<0;
	if(a==c&&b[0]==d[0]&&b[1]==d[1]) cout<<1;
	else cout<<0;
	if(a==c&&b[0]==d[0]&&b[1]==d[1]&&(b[2]<='C'&&d[2]<='C'||b[2]>'C'&&d[2]>'C')) cout<<1;
	else cout<<0;
	if(a==c&&b[0]==d[0]&&b[1]==d[1]&&(b[2]<='C'&&d[2]<='C'||b[2]>'C'&&d[2]>'C')&&abs(b[2]-d[2])==1) cout<<1;
	else cout<<0;
	return 0;
}