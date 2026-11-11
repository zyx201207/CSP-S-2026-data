#include <bits/stdc++.h>
using namespace std;
int c1, s1, c2, s2;
char a, b;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>a>>c2>>s2>>b;
	int x = int(a);
	int y = int(b);
	if(c1 == c2) {
		cout<<"1";
		if(s1 == s2) {
			cout<<"1";
			if((a == 'A' or a == 'B' or a == 'C') and (b == 'A' or b == 'B' or b == 'C')) {
				cout<<"1";
				if(abs(x - y) == 1) {
					cout<<"1";
				} else {
					cout<<"0";
				}
			} else if((a == 'D' or a == 'F') and (b == 'D' or b == 'F')) {
				cout<<"11";
			} else {
				cout<<"00";
			}
		} else {
			cout<<"000";
		}
	} else {
		cout<<"0000";
	}
	return 0;
}
