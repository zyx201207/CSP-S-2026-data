#include <bits/stdc++.h>
using namespace std;
string rc,rs,xc,xs;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rc>>rs>>xc>>xs;
	if (rc!=xc) {cout<<"0000";return 0;}
	cout<<1;
	if (rs[0]!=xs[0]||rs[1]!=xs[1]) {cout<<"000";return 0;}
	cout<<1;
	if (rs[2]>='A'&&rs[2]<='C'){
		if (xs[2]=='D'||xs[2]=='F') {cout<<"00";return 0;}
		cout<<1;
	}
	else if (xs[2]>='A'&&xs[2]<='C'){cout<<"00";return 0;}
	if (abs(rs[2]-xs[2])==1) cout<<1;
	else cout<<0;
	return 0;
}
