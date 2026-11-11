#include<bits/stdc++.h>
using namespace std;
string s1, s2;
string s, S;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>s1>>s>>s2>>S;
	int t1=s1[0]*10+s1[1], t2=s2[0]*10+s2[1];
	if (t1==t2) {
		cout<<1;
		int t1=s[0]*10+s[1], t2=S[0]*10+S[1];
		if (t1==t2) {
			cout<<1;
			if (s[2]<'D' && S[2]<'D' || s[2]>'C' && S[2]>'C') {
				cout<<1;
				if(abs(s[2]-S[2])==1) {
					cout<<1;
					return 0;
				} else {
					cout<<0;
				}
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
