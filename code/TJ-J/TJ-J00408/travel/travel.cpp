#include<bits/stdc++.h>
using namespace std;
int a,b,a1,b1;
char a2,b2;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> a1 >> a2 >> b >> b1 >> b2;
	if(a==b) {
		cout << 1;
		if(a1==b1) {
			cout << 1;
			if(a2<='C' && a2>='A' && b2<='C' && b2>='A') {
				cout << 1;
				if(a2+1==b2 && b2!='D' ) {
					cout << 1;
				} else if(b2+1==a2 && a2!='D' ) {
					cout << 1;
				} else {
					cout << 0;
				}
			} else if(a2<='E' && a2>='D' && b2<='E' && b2>='D') {
				cout << 1;
				if(a2+1==b2 && b2!='D') {
					cout << 1;
				} else if(b2+1==a2 && a2!='D' ) {
					cout << 1;
				} else {
					cout << 0;
				}
			} else {
				cout <<"00";
			}

		} else {
			cout << "000";
		}
	} else {
		cout << "0000";
	}
	
	return 0;
}
