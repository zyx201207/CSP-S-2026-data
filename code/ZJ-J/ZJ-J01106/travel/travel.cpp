#include<bits/stdc++.h>
#define int long long
using namespace std;
string s[3][3];
signed main() {
	freopen("travel.in","r",stdin);
	freopen("travel.ans","w",stdout);
	cin>>s[1][1]>>s[1][2]>>s[2][1]>>s[2][2];
	if(s[1][1]==s[2][1])cout<<"1";
	else cout<<"0000",exit(0);
	if(s[1][2].substr(0,2)==s[2][2].substr(0,2))cout<<"1";
	else cout<<"000",exit(0);
	if(s[1][2][2]<='C'&&s[2][2][2]<='C'||s[1][2][2]>='D'&&s[2][2][2]>='D')cout<<"1";
	else cout<<"00",exit(0);
	if(abs((int)s[1][2][2]-(int)s[2][2][2])==1) {
		if(s[1][2][2]=='C'&&s[2][2][2]=='D')cout<<"0";
		if(s[1][2][2]=='D'&&s[2][2][2]=='C')cout<<"0";
		cout<<"1";
	}
	else if(abs((int)s[1][2][2]-(int)s[2][2][2])==2){
		if(s[1][2][2]=='D'&&s[2][2][2]=='F'||s[1][2][2]=='F'&&s[2][2][2]=='D')cout<<"1";
		else cout<<"0";
	}
	else cout<<"0";
	exit(0);
}