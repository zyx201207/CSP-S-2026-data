#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,s="";
bool f=1;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> a >> b >> c >> d;
	if(a==c) s+='1';
	else f=0,s+='0';
	if(f==1&&b.substr(0,2)==d.substr(0,2)) s+='1';
	else f=0,s+='0';
	if(f==1&&b[2]<='C'&&d[2]<='C') s+='1';
	else {
		if(f==1&&b[2]>'C'&&d[2]>'C') {
			s+='1';
		} else f=0,s+='0';
	}
	if(f==1&&(b[2]+1==d[2]||b[2]-1==d[2])) {
		s+='1';
	} else {
		s+='0';
	}
	cout << s;
	return 0;
}
