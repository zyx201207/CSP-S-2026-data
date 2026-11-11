#include <bits/stdc++.h>
#define int long long
using namespace std;
string s,s1;
int n,m,nn,mm;
signed main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>nn>>s>>mm>>s1;
	if(nn==mm) {
		cout<<1;
	} else {
		cout<<"0000";
		return 0;
	}
	n=(s[0]-'0')*10+(s[1]-'0');
	m=(s1[0]-'0')*10+(s1[1]-'0');
	if(n==m) {
		cout<<1;
	} else {
		cout<<0;
	}
	if(n==m&&(s[2]<='C'&&s1[2]<='C')||(s[2]>'C'&&s1[2]>'C')) {
		cout<<1;
	} else {
		cout<<0;
	}
	if(n==m&&((s[2]<='C'&&s1[2]<='C')||(s[2]>'C'&&s1[2]>'C'))&&max(s[2],s1[2])-min(s[2],s1[2])==1) {
		cout<<1;
	} else {
		cout<<0;
	}
	return 0;
}
