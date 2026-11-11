#include<bits/stdc++.h>
using namespace std;
int c,cc,f;
string s,ss;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	for(int i=1; i<=4; i++) {
		if(i==1) {
			if(c==cc) {
				cout<<1;
				f=1;
			} else {
				cout<<0;
				f=0;
			}
		}
		if(i==2) {
			if(f==1) {
				if(s[0]==ss[0]&&s[1]==ss[1]) {
					cout<<1;
					f=1;
				} else {
					cout<<0;
					f=0;
				}
			} else {
				cout<<0;
				f=0;
			}
		}
		if(i==3) {
			if(f==1) {
				if(s[2]=='A'||s[2]=='B'||s[2]=='C') {
					if(ss[2]=='A'||ss[2]=='B'||ss[2]=='C') {
						cout<<1;
						f=1;
					}else{
						cout<<0;
						f=0;
					}
				} else if(s[2]=='D'||s[2]=='F') {
					if(ss[2]=='D'||ss[2]=='F') {
						cout<<1;
						f=1;
					}else{
						cout<<0;
						f=0;
					}
				}else{
					cout<<0;
					f=0;
				}
			} else {
				cout<<0;
				f=0;
			}
		}
		if(i==4) {
			if(f==1) {
				if(s[2]=='C'&&ss[2]=='D') {
					cout<<0;
				}
				if(s[2]=='A'&&ss[2]=='B') {
					cout<<1;
				} else if(s[2]=='B'&&ss[2]=='A') {
					cout<<1;
				} else if(s[2]=='B'&&ss[2]=='C') {
					cout<<1;
				} else if(s[2]=='C'&&ss[2]=='C') {
					cout<<1;
				} else if(s[2]=='D'&&ss[2]=='F') {
					cout<<1;
				} else if(s[2]=='F'&&ss[2]=='D') {
					cout<<1;
				} else {
					cout<<0;
				}
			}
			if(f==0) {
				cout<<0;
			}
		}
	}
	return 0;
}
