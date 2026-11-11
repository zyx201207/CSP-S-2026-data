#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a[1]==c[1]&&a[0]==c[0])cout<<1;
	else{ cout<<"0000";return 0;}
	if(b[1]==d[1]&&b[0]==d[0])cout<<1;
	else{cout<<"000";return 0;}
	if(b[2]=='C'&&d[2]=='D'||b[2]=='D'&&d[2]=='C'){cout<<"00";return 0;}
	if((b[2]+1)==d[2]||(b[2]-1)==d[2])cout<<"11";
	else{cout<<"00";return 0;}
	return 0;
}