#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
//这下应该可以AC这道题吧？ 
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2) {
		cout << "0000\n";
		return 0;
	}
	cout << 1;
	if(s1[0] != s2[0] || s1[1] != s2[1]) {
		cout << "000\n";
		return 0;
	}
	cout << 1;
	if((s1[2] - 'A' <= 2 && s2[2] - 'A' > 2) || (s2[2] - 'A' <= 2 && s1[2] - 'A' > 2)) {
		cout << "00\n";
		return 0;
	}
	cout << 1;
	if(abs(s1[2] - s2[2]) > 1) {
		cout << "0\n";
		return 0;
	}
	cout << 1 << "\n";
	return 0;
}
