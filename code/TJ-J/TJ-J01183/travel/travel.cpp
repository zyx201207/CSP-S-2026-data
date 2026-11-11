#include<bits/stdc++.h>
using namespace std;
int x,y;
string a,b,c,d;

bool check(char C) {
	if(C=='A'||C=='B'||C=='C') return 1;
	return 0;
}

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>> a >> b >> c >> d;
	if(a==c) {
		cout<<"1";
	} else {
		cout<<"0000";
		return 0;
	}
	x=(b[0]-'0')*10+(b[1]-'0');
	y=(d[0]-'0')*10+(d[1]-'0');
	if(x==y) {
		cout<<"1";
	} else {
		cout<<"000";
		return 0;
	}
	if(check(b[2])==check(d[2])) {
		cout<<"1";
	} else {
		cout<<"00";
		return 0;
	}
	if(check(b[2])==0||b[2]=='B'||d[2]=='B') {
		cout<<"1";
	} else {
		cout<<"0";
	}
	return 0;
}
