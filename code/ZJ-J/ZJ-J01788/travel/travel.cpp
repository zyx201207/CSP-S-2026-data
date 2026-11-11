#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
bool pd2(char c,char c1) {
	if(c=='A') {
		if(c1=='B') return true;
		return false;
	}
	if(c=='B') {
		if(c1=='A' || c1=='C') return true;
		return false;
	}
	if(c=='C') {
		if(c1=='B') return true;
		return false;
	}
	if(c=='D') {
		if(c1=='F') return true;
		return false;
	}
	if(c=='F') {
		if(c1=='D') return true;
		return false;
	}
}
bool pd1(char c,char c1) {
	if(c=='A') {
		if(c1=='B' || c1=='C') return true;
		return false;
	}
	if(c=='B') {
		if(c1=='A' || c1=='C') return true;
		return false;
	}
	if(c=='C') {
		if(c1=='B' || c1=='A') return true;
		return false;
	}
	if(c=='D') {
		if(c1=='F') return true;
		return false;
	}
	if(c=='F') {
		if(c1=='D') return true;
		return false;
	}
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) {
		cout<<"1";
		if(s1[0]==s2[0] && s1[1]==s2[1]) {
			cout<<"1";
			if(pd1(s1[2],s2[2])) {
				cout<<"1";
				if(pd2(s1[2],s2[2])) {
					cout<<"1";
				}
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
