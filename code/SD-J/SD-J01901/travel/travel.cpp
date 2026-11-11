#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

//const int MAXN = ;

void solve() {
	int c1, c2; string s1, s2; cin >> c1 >> s1 >> c2  >> s2;
	
	if (c1 == c2) {
		cout << "1";
	} else {
		cout << "0000" << endl;
		return ;
	}
	
	if (s1[0] == s2[0] && s1[1] == s2[1]) {
		cout << "1";
	} else {
		cout << "000" << endl;
		return ;
	}
	
	if (s1[2] == 'A') {
		if (s2[2] == 'B') {
			cout << "11" << endl;
		} else if (s2[2] == 'C'){
			cout << "10" << endl;
		} else {
			cout << "00" << endl;
		}
	} else if (s1[2] == 'B') {
		if (s2[2] == 'A' || s2[2] == 'C') {
			cout << "11" << endl;
		} else {
			cout << "00" << endl;
		}
	} else if (s1[2] == 'C') {
		if (s2[2] == 'B') {
			cout << 11 << endl;
		} else if (s2[2] == 'A') {
			cout << "10" << endl;
		} else {
			cout << "00" << endl;
		}
	} else if (s1[2] == 'D'){
		if (s2[2] == 'E') {
			cout << "11" << endl;
		} else {
			cout << "00" << endl;
		}
	} else {
		if (s1[2] == 'D') {
			cout << "11" << endl;
		} else {
			cout << "00" << endl;
		}
	}
	return ;
}

int main () {
	ios::sync_with_stdio();
	cin.tie(nullptr);
	
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	int T = 1; //cin >> T;
	while (T--) {
		solve();
	}
	
	return 0;
}

