#include<bits/stdc++.h>
using namespace std;
string rc,rs,xc,xs;
string ans = "";
int f (char a) {
	if (a == 'A' || a == 'B' || a == 'C') {
		return 1;
	}
	return 0;
}
bool g (char a,char b) {
	if (abs (a - b) == 1) {
		return 1;
	}
	return 0;
}
int main () {
	ios::sync_with_stdio (0);
	cin.tie (0);
	cout.tie (0);
	freopen ("travel.in","r",stdin);
	freopen ("travel.out","w",stdout);
	cin>>rc>>rs>>xc>>xs;
	if (rc == xc) {
		ans += "1";
	}
	else {
		ans += "0000";
		cout<<ans;
		return 0;
	}
	if (rs[0] == xs[0] && rs[1] == xs[1]) {
		ans += "1";
	}
	else {
		ans += "000";
		cout<<ans;
		return 0;
	}
	int r = f (rs[2]),x = f (xs[2]);
	if (r == x) {
		ans += "1";
	}
	else {
		ans += "00";
		cout<<ans;
		return 0;
	}
	if ((r == 0 && x == 0) || (g (rs[2],xs[2]))) {
		ans += "1";
	}
	else {
		ans += "0";
	}
	cout<<ans;
	return 0;
}
