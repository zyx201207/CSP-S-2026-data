#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	int e=(a[0]-'0')*10+(a[1]-'0');
	int f=(c[0]-'0')*10+(c[1]-'0');
	if(e==f) cout<<1;
	else{cout<<"0000";return 0;}
	e=(b[0]-'0')*10+(b[1]-'0');
	f=(d[0]-'0')*10+(d[1]-'0');
	if(e==f) cout<<1;
	else{cout<<"000";return 0;}
	if(b[2]<='C'&&d[2]<='C') cout<<1;
	else if(b[2]>='D'&&d[2]>='D'){cout<<11;return 0;}
	else{cout<<"00";return 0;}
	if((b[2]=='A'&&d[2]=='C')||(b[2]=='C'&&d[2]=='A')) cout<<0;
	else cout<<1;
	return 0;
}
