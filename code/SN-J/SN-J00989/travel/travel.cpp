#include<bits/stdc++.h>
using namespace std;
string s1, s2, s3, s4;
bool f1, f2;
long long n;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> s1 >> s2 >> s3 >> s4;
	if(s1 != s3) {
		cout << "0000";
	} else {
		if(s2[0] == s4[0] && s2[1] == s4[1]) {
			if(s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C') f1 = 1;
			if(s4[2] == 'A' || s4[2] == 'B' || s4[2] == 'C') f2 = 1;
			if(f1 == f2) {
				if(abs(int(s2[2]) - int(s4[2])) == 1) cout << 1111;
				else cout << 1110;
			} else {
				cout << 1100;
			}
		} else {
			cout << 1000;
		}
	}
	return 0;
}
