#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("trave.in","r",stdin);
	freopen("trave.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a,c;
	string b,d;
	cin>>a>>b>>c>>d;
	if(a==c) cout<<"1";
	else{ cout<<"0000";return 0;}
	if(b[0]==d[0]&&b[1]==d[1]) cout<<"1";
	else { cout<<"000";return 0;}
	if((b[2]=='D'&&d[2]=='F')||(b[2]=='D'&&d[2]=='F')) cout<<"11";
	else if((b[2]>='A'&&b[2]<='C')&&(d[2]>='A'&&d[2]<='C')){
		cout<<"1";
		if((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&d[2]=='A')) cout<<"1";
		else if((b[2]=='B'&&d[2]=='C')||(b[2]=='C'&&d[2]=='B')) cout<<"1";
		else if((b[2]=='A'&&d[2]=='C')||(b[2]=='C'&&d[2]=='A'))cout<<"0";
	}
	else { cout<<"00";return 0;}
	return 0;
} 
