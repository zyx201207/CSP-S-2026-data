#include<bits/stdc++.h>
using namespace std;
string cn1,sn1,cn2,sn2;
string t;
bool xl(char xx,char yy) {
	if(xx=='A') {
		if(yy=='B') return true;
	} else if(xx=='B') {
		if(yy=='A'||yy=='C') return true;
	} else {
		if(yy=='B') return true;
	}
	return false;
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cn1>>sn1>>cn2>>sn2;
	if(cn1==cn2) {
		t+='1';
		if(sn1[0]==sn2[0]&&sn1[1]==sn2[1]) {
			t+='1';
			if(sn1[2]=='A'||sn1[2]=='B'||sn1[2]=='C') {
				if(sn2[2]=='B'||sn2[2]=='A'||sn2[2]=='C') {
					t+='1';
					if(xl(sn1[2],sn2[2])) {
						t+='1';
					} else t+='0';
				} else {
					t+='0';
					t+='0';
				}
			} else {
				if(sn2[2]=='D'||sn2[2]=='F') {
					t+='1';
					t+='1';
				} else {
					t+='0';
					t+='0';
				}
			}
		} else {
			t+='0';
			t+='0';
			t+='0';
		}
	} else {
		t+='0';
		t+='0';
		t+='0';
		t+='0';
	}
	cout<<t;
	return 0;
}
