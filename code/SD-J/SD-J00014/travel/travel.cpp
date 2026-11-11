#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string c,d;
	cin>>a>>c>>b>>d;
	int c1=(c[0]-'0')*10+(c[1]-'0');
	int d1=(d[0]-'0')*10+(d[1]-'0');
	bool isc=0,isd=0;
	if(c[2]<='C') {
		isc=1;
	}
	if(d[2]<='C') {
		isd=1;
	}
	if(a==b) {
		cout<<1;
	} else {
		cout<<"0000";
		return 0;
	}
	if(c1==d1) {
		cout<<1;
	} else {
		cout<<"000";
		return 0;
	}
	if(isc==isd) {
		cout<<1;
	} else {
		cout<<"00";
		return 0;
	}
	if((isc==isd&&isc==0)||(abs(c[2]-d[2])==1)) {
		cout<<1;
	} else {
		cout<<0;
	}
	return 0;
}
