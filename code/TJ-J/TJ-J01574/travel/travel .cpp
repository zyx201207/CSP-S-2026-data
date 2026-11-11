#include <bits/stdc++.h>
using namespace std;
char ans[10];

int main() {

	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	string ca, cb;
	string sa, sb;
	cin >> ca >> sa >> cb >> sb;
	int cnt = 0;
	for (int i = 0; i < 2; i++) {
		if (ca[i] == cb[i]) {
			cnt++;
		}
	}
	if (cnt == 2) {
		cout << "1";
	} else {
		cout << "0000";
		return 0;
	}

	cnt = 0;
	for (int i = 0; i < 2; i++) {
		if (sa[i] == sb[i]) {
			cnt++;
		}
	}
	if (cnt == 2) {
		cout << "1";
	} else {
		cout << "000";
		return 0;
	}

	bool f = false;
	if (sa[2] == 'A' || sa[2] == 'B' || sa[2] == 'C') {
		if (sb[2] == 'A' || sb[2] == 'B' || sb[2] == 'C') {
			cout << "1";
			f = true;
		}
	} else {
		if (sb[2] == 'D' || sb[2] == 'F') {
			cout << "1";
			f = true;
		}
	}
	if (f == false) {
		cout << "00";
		return 0;
	}

	if ((sa[2] == 'A' && sb[2] == 'B') || (sa[2] == 'B' && sb[2] == 'A') || (sa[2] == 'C' && sb[2] == 'B') || (sa[2] == 'B'
	        && sb[2] == 'C')
	        || (sa[2] == 'D' && sb[2] == 'F') || (sa[2] == 'F' && sb[2] == 'D')) {
		cout << '1';
	} else {
		cout << '0';
	}
	return 0;
}

