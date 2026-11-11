#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;
string s1,s2;
int c1,c2;
//priority_queue
//lower_bound upper_bound
void solve() {
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) {
		cout<<1;
	} else {
		cout<<"0000";
		return;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]) {
		cout<<1;
	} else {
		cout<<"000";
		return;
	}
	if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')) {
		cout<<1;
	} else {
		cout<<"00";
		return;
	}
	if(s1[2]=='D'&&s2[2]=='E') {
		cout<<1;
		return;
	} else if(s1[2]=='E'&&s2[2]=='D') {
		cout<<1;
		return;
	}
	if(s1[2]=='C'&&s2[2]=='B') {
		cout<<1;
		return;
	} else if(s1[2]=='B'&&s2[2]=='C') {
		cout<<1;
		return;
	}
	if(s1[2]=='B'&&s2[2]=='A') {
		cout<<1;
		return;
	} else if(s1[2]=='A'&&s2[2]=='B') {
		cout<<1;
		return;
	}
	cout<<0;
	return;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int _ = 1;
//	cin>>_;
	while(_--) {
		solve();
	}
	return 0;
}
