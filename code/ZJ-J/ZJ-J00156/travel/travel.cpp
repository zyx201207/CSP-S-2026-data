#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
bool f2 = 0, f3 = 0, f4 = 0;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2) {
		cout << "0000\n";
		return 0;
	}
	if(s1[0] == s2[0] && s1[1] == s2[1]){
		f2 = 1;
		char a = s1[2], b = s2[2];
		if(a == 'A' && b == 'B') f3 = 1, f4 = 1;
		if(a == 'B' && b == 'A') f3 = 1, f4 = 1;
		if(a == 'A' && b == 'C') f3 = 1;
		if(a == 'C' && b == 'A') f3 = 1;
		if(a == 'B' && b == 'C') f3 = 1, f4 = 1;
		if(a == 'C' && b == 'B') f3 = 1, f4 = 1;
		if(a == 'F' && b == 'D') f3 = 1, f4 = 1;
		if(a == 'D' && b == 'F') f3 = 1, f4 = 1;
	}
	cout << 1 << f2 << f3 << f4 << '\n';
	return 0;
}