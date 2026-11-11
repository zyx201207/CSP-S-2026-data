#include<bits/stdc++.h>
using namespace std;
void _file(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
}
string a,b,x,y;
int fl=1,tmpgg=0;
int main(){
	_file();
	cin>>a>>b>>x>>y;
	if(a==x) cout<<1;
	else cout<<0,fl=0;
	if(b[0]==y[0]&&b[1]==y[1]&&fl) cout<<1,tmpgg=1;
	else cout<<0,fl=0;
	if(tmpgg&&((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(y[2]=='A'||y[2]=='B'||y[2]=='C')||(b[2]=='D'||b[2]=='F')&&(y[2]=='D'||y[2]=='F'))) cout<<1;
	else cout<<0,fl=0;
	if(fl&&!(b[2]=='A'&&y[2]=='C'||b[2]=='C'&&y[2]=='A')) cout<<1;
	else cout<<0;
	return 0;
}


