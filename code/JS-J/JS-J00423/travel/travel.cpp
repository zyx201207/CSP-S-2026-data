#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	cout<<(a==c);
	cout<<((a==c)&&(b[0]==d[0]&&b[1]==d[1]));
	cout<<(((a==c)&&(b[0]==d[0]&&b[1]==d[1]))&&((b[2]<='C'&&d[2]<='C')||(b[2]>'C'&&d[2]>'C')));
	cout<<(((a==c)&&(b[0]==d[0]&&b[1]==d[1]))&&(((b[2]<='C'&&d[2]<='C')||(b[2]>'C'&&d[2]>'C'))&&((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&d[2]=='A')||(b[2]=='C'&&d[2]=='B')||(b[2]=='B'&&d[2]=='C')||(b[2]=='F'&&d[2]=='D')||(b[2]=='D'&&d[2]=='F'))));
	return 0;
}					
