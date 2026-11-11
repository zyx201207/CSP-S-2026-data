#include <bits/stdc++.h>
using namespace std;
int c1, s1, c2, s2;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == s1) {
	 cout << 1;
	} else cout << "0";

	if(c1 == s1 && c2 - 'A' + 1 == s2 - 'A' + 1) {
	cout << 1;
	} cout << "0";
	if(c1 == s1 && c2 - 'A' + 1 == s2 - 'A' + 1) {
		cout << 1;
	}  else cout << "0";
	
	if(s1 == c1 && s2 == c2) {
		
	 cout << 1;
	}else cout << "0";
	return 0;
} 
