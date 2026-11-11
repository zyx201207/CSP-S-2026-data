#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string a, sa, b, sb, la = "", lb = "";
	cin >> a >> sa >> b >> sb;
	
	if (a == b) cout << "1";
	else {
		cout << "0000";
		return 0;
	}
	
	la += sa[0] + sa[1];
	lb += sb[0] + sb[1];
	if (la == lb) cout << "1";
	else {
		cout << "000";
		return 0;
	}
	
	if ((sa[2] <= 'C' && sb[2] <= 'C')||(sa[2]>='D'&&sb[2]>='D')) cout << "1";
	else {
		cout << "00";
		return 0;
	}
	if (sa[2] <= 'C' && sb[2] <= 'C') {
		if (sa[2] == 'B' || sb[2] == 'B') cout << "1";
		else cout << "0";
	} else {
		cout << "1";
	}
	
	return 0;
} 
