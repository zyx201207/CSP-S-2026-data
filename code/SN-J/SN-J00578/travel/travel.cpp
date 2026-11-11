#include <bits/stdc++.h>
using namespace std;
string c,s,c1,s1;
char x[4]= {'1','1','1','1'};
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>s>>c1>>s1;
	if(c==c1) {
		x[0]='1';
		if(s[0]==s1[0]&&s[1]==s1[1]) {
			x[1]='1';
			if(s[2]>='A'&&s1[2]<='C'&&s[2]<='C'&&s1[2]>='A'||s[2]>='D'&&s1[2]>='D'&&s[2]<='F'&&s1[2]<='F') {
				x[2]=='1';
				if(s[2]=='A'&&s1[2]=='B'||s[2]=='B'&&s1[2]=='C'||s1[2]=='A'&&s[2]=='B'||s1[2]=='B'&&s[2]=='C'||s[2]=='D'&&s1[2]=='F'||s1[2]=='D'&&s[2]=='F') {
					x[3]=='1';
				} else x[3]=='0';
			} else x[2]='0',x[3]='0';
		} else x[1]='0',x[2]='0',x[3]='0';
	} else x[0]='0',x[1]='0',x[2]='0',x[3]='0';
	cout<<x[0]<<x[1]<<x[2]<<x[3];
	return 0;
}
