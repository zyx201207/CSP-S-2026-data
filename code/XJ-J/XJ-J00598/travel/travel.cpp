#include<bits/stdc++.h>
using namespace std;
int a,c;
char b[3],d[3];
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>b[1]>>b[2]>>b[3]>>c>>d[1]>>d[2]>>d[3];
	if(a!=c) {
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	if(b[1]==d[1] && b[2]==d[2]) {
		cout<<1;
	} else {
		cout<<"000";
		return 0;
	}
	if(b[3]=='D' || b[3]=='F') {
		if(d[3]=='D' || d[3]=='F') {
			cout<<"11";
		} else {
			cout<<"00";
		}
	}
	if(b[3]>='A' && b[3]<='C') {
		if(d[3]>='A' && d[3]<='C') {
			if(b[3]=='A' && d[3]=='C' || b[3]=='C' && d[3]=='A') {
				cout<<"10";
			} else {
				cout<<"11";
			}
		} else {
			cout<<"00";
		}
	}
	return 0;
}