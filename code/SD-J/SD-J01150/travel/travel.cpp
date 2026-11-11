#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
inline void fast_io() {
	ios::sync_with_stdio(0);
	cin.tie(0);
} 
string c1, s1, c2, s2;
int main() {
	fast_io();
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2) {
		cout << 1;
		ll p1 = s1[0] + s1[1];
		ll p2 = s2[0] + s2[1];
		if(p1 == p2) {
			cout << 1;
			char l1 = s1[2];
			char l2 = s2[2];
			bool f1, f2;
			f1 = f2 = 0;
			if(l1 == 'A' || l1 == 'B' || l1 == 'C') f1 = 1;
			if(l2 == 'A' || l2 == 'B' || l2 == 'C') f2 = 1;
			if(f1 == f2) {
				cout << 1;
				if(abs(int(l1) - int(l2)) == 1) {
					cout << 1;
				}
				else {
					cout << 0;
				}
			}
			else {
				cout << "00";
			}
		}
		else {
			cout << "000";
		}
	}
	else {
		cout << "0000";
	}
	
	return 0;
}

