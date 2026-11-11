#include<bits/stdc++.h>
using namespace std;
struct seat{
	int c;
	string s;
};
int main() {
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	seat r , x;
	cin >> r.c >> r.s >> x.c >> x.s;
	if(r.c == x.c) {
		cout << 1;
		if(r.s[0] == x.s[0] && r.s[1] == x.s[1]) {
			cout << 1;
			char a = r.s[2] , b = x.s[2];
			if(((a == 'A' || a == 'B' || a == 'C') && (b == 'D' || b == 'F')) || ((b == 'A' || b == 'B' || b == 'C') && (a == 'D' || a == 'F'))) {
				cout << 0 << 0; 
			} else {
				cout << 1;
				int m = r.s[2] - 'A' , n = x.s[2] - 'A';
				if(m - n == 1 || n - m == 1) {
					cout << 1;
				} else cout << 0;
			}
		} else {
			cout << 0 << 0 << 0;
		}
	} else cout << 0 << 0 << 0 << 0;
	return 0;
}

