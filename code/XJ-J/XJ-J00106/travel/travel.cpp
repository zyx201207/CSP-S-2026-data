#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
string c1, s1, c2, s2;

int main() {
	
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	string pai1 = "";
	string pai2 = "";
	for(int i = 0; i < 2; i ++) {
		pai1 += s1[i];
		pai2 += s2[i];
	}
	bool ok1 = (c1 == c2);
	bool ok2 = (pai1 == pai2);
	bool ok3 = 0;
	bool ok4 = 0;
	if(s1[2] <= 'C' && s2[2] <= 'C') {
		ok3 = 1;
	}
	else if(s1[2] >= 'D' && s2[2] >= 'D') {
		ok3 = 1;
	}
	
	if((s1[2] == 'A' && s2[2] == 'B') || (s1[2] == 'B' && s2[2] == 'C') || (s1[2] == 'D' && s2[2] == 'F'))  {
		ok4 = 1;
	}
	if((s2[2] == 'A' && s1[2] == 'B') || (s2[2] == 'B' && s1[2] == 'C') || (s2[2] == 'D' && s1[2] == 'F'))  {
		ok4 = 1;
	}
	if(ok1 == 0) {
		cout << "0000";
	}
	else if(ok2 == 0) {
		cout << "1000";
	}
	else if(ok3 == 0) {
		cout << "1100";
	}
	else if(ok4 == 0) {
		cout << "1110";
	}
	else {
		cout << "1111";
	}
	
	return 0;
} 
