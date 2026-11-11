#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("trauel.in","r",stdin);
	freopen("trauel.out","w",stdout);
	string a,b,a2,b2;
	cin>>a>>b>>a2>>b2;
	if(a==a2) {
		cout<<1;
	} else {
		cout<<"0000";
		return 0;
	}
	if(b[0]==b2[0]&&b[1]==b2[1]) {
		cout<<1;
	} else {
		cout<<"000";
		return 0;
	}
	if((b[2]=='A'||b[2]=='B'||b[2]=='C'&&b2[2]=='A'||b2[2]=='B'||b2[2]=='C')||(b[2]=='E'||b[2]=='F'&&b2[2]=='E'||b2[2]=='F')) {
		cout<<1;
	} else {
		cout<<"00";
		return 0;
	}
	if(b[2]-1==b2[2]||b[2]+1==b2[2]) {
		cout<<1;
	} else {
		cout<<"0";
		return 0;
	}
	return 0;
}
