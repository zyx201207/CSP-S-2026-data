#include<bits/stdc++.h>
using namespace std;
long long int a1, a2, s1[5], s2[5], k = 1;
string b1, b2;
int main () {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a1 >> b1 >> a2 >> b2;
	if (a1 == a2) {
		cout << 1;
	}
	else {
		cout << 0 << 0 << 0 << 0;
		return 0;
	}
	if (b1[1] == b2[1] && b1[0] == b2[0]) {
		cout << 1;
	}
	else {
		cout << 0 << 0 << 0;
		return 0;
	}
	if ((b1[2] == 'A' || b1[2] == 'B' || b1[2] == 'C') && (b2[2] == 'A' || b2[2] == 'B' || b2[2] == 'C')){
		cout << 1;
	}
	else {
		if ((b1[2] == 'D' || b1[2] == 'E') && (b2[2] == 'D' || b2[2] == 'E')) {
			cout << 11;
			return 0;
		}
		else {
			cout << 0 << 0;
			return 0;
		}
	}
	if ((b1[2] == 'A' && b2[2] == 'B') || (b2[2] == 'A' && b1[2] == 'B') || (b1[2] == 'C' && b2[2] == 'B') || (b2[2] == 'C' && b1[2] == 'B')) {
		cout << 1;
	}
	else {
		cout << 0;
	}
	return 0;
}
