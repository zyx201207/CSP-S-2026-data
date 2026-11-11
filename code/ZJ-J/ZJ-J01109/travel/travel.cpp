#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2,l1,l2;
int Hallway(char ch) {
	if (ch=='A') return 0;
	if (ch=='B') return 0;
	if (ch=='C') return 0;
	if (ch=='D') return 1;
	if (ch=='F') return 1;
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	l1=s1.substr(0,2);
	l2=s2.substr(0,2);
	s1.erase(0,2);s2.erase(0,2);
	if (c1==c2) {
		cout<<"1";
		if (l1==l2) {
			cout<<"1";
			if (Hallway(s1[0])==Hallway(s2[0])) {
				cout<<"1";
				if (abs(s1[0]-s2[0])==1) cout<<"1";
				else cout<<"0";
			}
			else {
				cout<<"00";
			}
		}
		else {
			cout<<"000";
		}
	}
	else {
		cout<<"0000";
	}
	return 0;
}
