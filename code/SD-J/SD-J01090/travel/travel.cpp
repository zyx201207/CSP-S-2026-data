#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

const int INF = 0x3f3f3f3f;
const ll INF2 = 0x3f3f3f3f3f3f3f3f;

int c1, c2;
string s1, s2;

int r1, r2;
int cc1, cc2;

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(), cin.tie(0);

	cin >> c1 >> s1 >> c2 >> s2;
	
	string t1 = s1.substr(0, 2);
	string t2 = s2.substr(0, 2);
	r1 = stoi(t1);
	r2 = stoi(t2);
	cc1 = s1[2];
	cc2 = s2[2];

	if (c1 == c2) {
		cout << 1;
		if (r1 == r2) {
			cout << 1;
			if (cc1 <= 'C'&&cc2 <= 'C') {
				cout << 1;
				if (cc1 > cc2) swap(cc1, cc2);
				
				if (cc2 == cc1+1) {
					cout << 1;
				} else {
					cout << 0;
				}
			} else if (cc1 > 'C' && cc2 > 'C') {
				cout << "11";
			} else cout << "00";
		} else cout << "000";
	} else cout << "0000";

	return 0;
}
/*
02 01A 02 01B
02 01C 02 01A
02 01C 02 01D
*/
