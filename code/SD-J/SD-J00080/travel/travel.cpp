#include<bits/stdc++.h>
using namespace std;
int tongyice(char a,char b) {
	if(a=='A') {
		if(b=='B'||b=='C') {
			return 1;
		} else {
			return 0;
		}
	} else if(a=='B') {
		if(b=='A'||b=='C') {
			return 1;
		} else {
			return 0;
		}
	} else if(a=='C') {
		if(b=='A'||b=='B') {
			return 1;
		} else {
			return 0;
		}
	} else {
		if(a=='D') {
			if(b=='F') {
				return 1;
			} else {
				return 0;
			}
		} else {
			if(b=='D') {
				return 1;
			} else {
				return 0;
			}
		}
	}
}
int xiangling(char a,char b) {
	if(a=='A'||a=='C') {
		if(b=='B') {
			return 1;
		} else {
			return 0;
		}
	} else if(a=='B') {
		if(b=='A'||b=='C') {
			return 1;
		} else {
			return 0;
		}
	} else if(a=='D') {
		if(b=='F') {
			return 1;
		} else {
			return 0;
		}
	} else {
		if(b=='D') {
			return 1;
		} else {
			return 0;
		}
	}
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string rn,rh,xn,xh;//r¡¢xµÄÃû×ÖºÍ×øºÅ ;
	cin>>rn>>rh>>xn>>xh;
	if(rn!=xn) {
		cout<<"0000";
		return 0;
	} else {
		cout<<1;
		if(rh[0]==xh[0]&&rh[1]==xh[1]) {
			cout<<1;
			cout<<tongyice(rh[2],xh[2]);
			if(tongyice(rh[2],xh[2])==1) {
				cout<<xiangling(rh[2],xh[2]);
			} else {
				cout<<0;
			}
		} else {
			cout<<"000";
		}
	}
	return 0;
}
