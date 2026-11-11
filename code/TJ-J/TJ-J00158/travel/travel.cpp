#include<bits/stdc++.h>
using namespace std;
bool x,y,z;
string a,b,c,d;
string q="ABCEDF";
bool check1() {
	if(a[0]==b[0] && a[1]==b[1])
		return 1;
	else
		return 0;
}
bool check2() {
	if((c[0]==d[0] &&  c[1]==d[1])  &&  x==1)
		return 1;
	else
		return 0;
}
bool check3() {
	if((((((c[2]-'A')<3) && ((d[2]-'A')<3))||((((c[2] - 'A' ) >= 3 ) && ((d[2]-'A')>=3))))&& x==1) &&   y==1){
		return 1;
	}
	else{
		return 0;
	}
}

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>c>>b>>d;
	if(check1()) {
		x=1;
		cout<<1;
	} else {
		cout<<0;
	}
	if(check2()) {
		y=1;
		cout<<1;
	} else {
		cout<<0;
	}
	if(check3()) {
		z=1;
		cout<<1;
	} else {
		cout<<0;
	}
	if(x==1 && y==1 && z==1 ) {
		for(int i=0; i<4; i++) {
			if((c[2]==q[i] && d[2]==q[i+1])|| (d[3]==q[i] && c[3]==q[i+1])) {
				cout<<1;
				return 0;
			}
		}
	}
	cout<<0;
}
