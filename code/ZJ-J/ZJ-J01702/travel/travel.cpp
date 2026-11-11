#include <bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3) {
		if(s2[0]==s4[0]&&s2[1]==s4[1]) {
			char x1=s2[2];
			char x2=s4[2];
			if((x1<='C'&&x2<='C')||(x1>'C'&&x2>'C')) {
				if(abs(x1-x2)==1||((x1=='D'&&x2=='F')||(x1=='F'&&x2=='D'))) {
					cout<<"1111";
				} else {
					cout<<"1110";
				}
			} else {
				cout<<"1100";
			}
		} else {
			cout<<"1000";
		}
	} else {
		cout<<"0000";
	}
	return 0;
}
