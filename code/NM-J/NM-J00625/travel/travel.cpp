#include<bits/stdc++.h>
using namespace std;

int main () {
	freopen ("tavel.in","r",stdin);
	freopen ("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	char b1,d1;
	for(int i=0; i<2; i++) {
		b1=b1+b[i];
		d1=d1+d[i];
	}
	if(a==c) {
		cout<<"1";
	} else {
		cout<<"0000";
		return 0;
	}
	if(b1==d1 ) {
		cout<<"1";
	} else {
		cout<<"000";
		return 0;
	} 
	if((b[3]>='A'&&b[3]<='C')&&(d[3]>='A'&&d[3]<='C')) {
		if(d[3]=='A'&&b[3]=='B') {
			cout<<"11";
		}else if(d[3]=='B'&&b[3]=='C') {
			cout<<"11";
		} else if(d[3]=='B'&&b[3]=='A') {
			cout<<"11";
		}else if(d[3]=='C'&&b[3]=='B') {
			cout<<"11";
		}else {
			cout<<"10";
		}
	} else {
		if(d[3]=='D'||d[3]=='F') {
			cout<<"11";
		}
		cout<<"00";
	}
	return 0;
}
