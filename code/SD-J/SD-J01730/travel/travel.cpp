#include<bits/stdc++.h> 
#define long long long long
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	string b1="",d1="";
	b1+=b[0],b1+=b[1];
	d1+=d[0],d1+=d[1];
	if(a!=c){cout<<"0000";return 0;}
	if(b1!=d1){cout<<1000;return 0;}
	if(b[2]<='C'&&d[2]>'C'){cout<<1100;return 0;}
	if(b[2]>'C'&&d[2]<='C'){cout<<1100;return 0;}
	if(b[2]=='A'&&d[2]=='B'){cout<<1111;return 0;}
	if(b[2]=='B'&&d[2]=='A'){cout<<1111;return 0;}
	if(b[2]=='C'&&d[2]=='B'){cout<<1111;return 0;}
	if(b[2]=='B'&&d[2]=='C'){cout<<1111;return 0;}
	if(b[2]=='D'&&d[2]=='E'){cout<<1111;return 0;}
	if(b[2]=='E'&&d[2]=='D'){cout<<1111;return 0;}
	cout<<1110;
	return 0;
}

